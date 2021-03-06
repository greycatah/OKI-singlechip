#include<stdio.h>


#define PORT_DEPLOY_OK   (0) //成功 
#define PORT_DEPLOY_FAIL (-1)//失败 

#define PORT_LOW  (0) //检查状态 
#define PORT_HIGH (1) //检查状态 

/********************************** 
 * 函数名:P0D_init 
 * 功能: P0口配置初始化 
 * 参数: bit0:
           P00_MODE_LOW   (0)  //P00口配置为低电平 
           P00_MODE_HIGH   (1)  //P00口配置为高电平 
         bit1:
           P01_MODE_LOW   (0)  //P01口配置为低电平 
           P01_MODE_HIGH   (1)  //P01口配置为高电平 
         bit2:
           P02_MODE_LOW   (0)  //P02口配置为低电平 
           P02_MODE_HIGH   (1)  //P02口配置为高电平 
         bit3:
           P03_MODE_LOW   (0)  //P03口配置为低电平 
           P03_MODE_HIGH   (1)  //P03口配置为高电平 
         bit4:
           P04_MODE_LOW   (0)  //P04口配置为低电平 
           P04_MODE_HIGH   (1)  //P04口配置为高电平 
 * 返回: int 
***********************************/
int P0D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
  unsigned int P00D,P01D,P02D,P03D,P04D;
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P00D = bit0; P01D = bit1;
	P02D = bit2; P03D = bit3;
	P04D = bit4;
	printf("%d,%d,%d,%d,%d\n", P00D,P01D,P02D,P03D,P04D);
   return (PORT_DEPLOY_OK);
  }

int main()
  {
  	unsigned int A,B,C,D,E;
	  int SUM;
  	scanf("%d,%d,%d,%d,%d",&A,&B,&C,&D,&E);
  	 SUM=P0D_init(A, B, C, D, E);
  	 printf("SUM=%d", SUM);
  	
  }