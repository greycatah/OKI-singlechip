#include<stdio.h>

/**********************************
 * 功能: MAX/MIN加功能函数 
 * 参数:  Tim_m(闹钟与时钟设置标志位)
		  Tim_c((闹钟模式标志位), Tim_t(时钟模式标志位)
 * 返回: 无
**********************************/
  void keyMAI_var(uint Tim_m, uint Tim_c, uint Tim_t, uint *weeK, uint *CLK_BULCD)
   {
   	  if(Tim_m == 1)
   	   {
 	    switch(Tim_c)
   	   	 {  
   	   	 case  1: {var_mode(&C_TEN, 23, 0); if(*CLK_BULCD == 1)*CLK_BULCD=2; break;}
   	   	 case  2: {var_mode(&C_MAR, 59, 0); if(CLK_mode == 1)*CLK_BULCD=2; break;}
   	   	 case  3: {var_mode(CLK_BULCD, 3, 1); break;} 
   	   	 } 
   	   }
      if(Tim_m == 2)
       {
       	switch(Tim_t) 
       	 { 
       	 case 1:
       	  {
   	  	   Tyear++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1); break;
          }
         case 2:
          {
   	  	   Tmoon++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1); break;        	
          }
         case 3:
          {
   	  	   Tday++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1); break;         	
          }
         case 4: var_mode(&TEN, 23, 0); break;
         case 5: var_mode(&MAR, 59, 0); break;
         } 
       }
   } 
   
 
/**********************************
 * 功能: 闹钟功能函数 
 * 参数:  
 * 返回: 无
**********************************/  
void CLK_BUzzLCD(uint CLK_MO)
 {
   	switch(CLK_MO) 
   	 {
 	  case 1: UI_BUZZ(1, 0);break;
	  case 2: UI_BUZZ(1, 1);break;
	  case 3: UI_BUZZ(1, 1);break;	
     }
  }
  
  
/**********************************
 * 功能: 年，时钟，闹钟功能函数  
 * 参数: *K_mod(年与时钟切换)，mode_12_24(12/24切换标志位),
          ap_m(上午，下午标志位), K_tim(显示功能允许位)  
 * 返回: 无
**********************************/ 
void LCD_year_time(uint K_mod,uint mode_12_24, uint ap_m, uint K_tim)
 {
  switch(K_tim)
   {
    case 0://主界面 
    {
     AP_Mjudge(TEN, &am_plcd);
     switch(K_mod)
     {
   	  case 0:
	   {
	   	 UI_MODA(2); 
	   	 UI_YE(Tyear, K_mod, 1);
   		 UI_TIME(TEN, MAR, mode_12_24, 1, 1);
         UI_AIS_APM(K_tim, ap_m, mode_12_24);
         UI_YEAR_TIME(P_A, K_tim, 0, Tmoon, Tday);
         UI_all_CLMON(week_zhi, 0, 2);
         UI_P(P_A, 3); break;
   	   }
	  case 1:
	   {
	   	 UI_MODA(2); 
   		 UI_YE(Tyear, K_mod, 1);
	     UI_AIS_APM(K_tim, 0, 0);
         UI_YEAR_TIME(P_A, K_tim, 0, Tmoon, Tday);
         UI_all_CLMON(week_zhi, 0, 2);
         UI_P(P_A, 2);break;
   	   }
      }	
      break;
    }
   case 1: //闹钟设置界面 
     {  
	    AP_Mjudge(C_TEN, &am_plcd);
        UI_MODA(K_tim);
        UI_YE(Tyear, 0, Ds_P);
        UI_all_CLMON(1, CLK_mode, K_tim);
        UI_AIS_APM(K_tim, ap_m , mode_12_24);
	   switch(TIM_clock)
        {
   	     case 1: 
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 2, Ds_P); 
	         CIK_glint(1, CLK_mode); break;
	      }
         case 2:
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 3, Ds_P);
	         CIK_glint(1, CLK_mode); break;
	      }
         case 3:
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 1, Ds_P);
	         CIK_glint(Ds_P, CLK_mode); break;
	      }
     	 }
  	   UI_P(Ds_P, 1); break;
	 }	
    case 2: //时钟设置界面 
     { 
       AP_Mjudge(TEN, &am_plcd);
       UI_MODA(K_tim);
       UI_all_CLMON(week_zhi, 0, K_tim);
       switch(TIM_time)
        {
      	case 1:
         {
            UI_YE(Tyear, 2, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
         	UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2); break;
         }
        case 2:
         {
         	UI_YE(Tyear, 1, Ds_P);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
            UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2); break;
         }       
        case 3:
         {
         	UI_YE(Tyear, 1, P_A);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
            UI_AIS_APM(K_tim, 0 , 0);
       	    UI_P(Ds_P, 2); break;
         }       
        case 4:
         {
         	UI_YE(Tyear, 0, P_A);
         	UI_YEAR_TIME(P_A, 0, 0, Tmoon, Tday);
         	UI_TIME(TEN, MAR, mode_12_24, 2, Ds_P);
         	UI_AIS_APM(K_tim, ap_m , mode_12_24);
         	UI_P(Ds_P, 1); break;
         } 
        case 5:
         {
         	UI_YE(Tyear, 0, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
       	    UI_TIME(TEN, MAR, mode_12_24, 3, Ds_P);
         	UI_AIS_APM(K_tim, ap_m , mode_12_24);
       	    UI_P(Ds_P, 1); break;
         } 
        } 
	  break;	 
     } 
   }
}


/*********************************
 * 功能: 按键(蜂鸣器)
 * 参数: 无
 * 返回: 无
**********************************/
void key_buzz()
 {
   MD0TMP = 0x03; // 配置蜂鸣器模式
   M0RUN = 1; // 开启蜂鸣器	
  }   
  
/*********************************
 * 功能: 开机，闹钟（蜂鸣器） 
 * 参数: 无
 * 返回: 无
**********************************/  
void ON_clk_buzz()
 {
   MD0TMP = 0x00; // 配置蜂鸣器模式
   M0RUN=1;  // 开启蜂鸣器 
   Init_Times2(); 
  }  

/**********************************
 * 功能: 闹钟模式选择 
 * 参数: B_mod(输入模式接口)，*Buzz_X(指针模式接口) 
 * 返回: 无
**********************************/ 
void BUZZ_mode(uint B_mod, uint *Buzz_X)
 {
    *Buzz_X=B_mod;	
    ON_clk_buzz();
 }

/**********************************
 * 功能: 闹钟频率切割选择 
 * 参数: Buzz_X(模式接口) 
 * 返回: 无
**********************************/ 
void BUZZ_delay(uint Buzz_X) 
 {
   static int k=0;
   if(M0RUN==1)
 	switch(Buzz_X)
 	 {
 	 	case 1:{if(++k==3)M0RUN=0; Init_Times2();}
 	 	case 2:{if(++k==6)M0RUN=0; Init_Times2();}
 	 	case 3:{if(++k==12)M0RUN=0; Init_Times2();}
 	 	case 4:{if(++k==16)M0RUN=0; Init_Times2();}
 	 }
 }