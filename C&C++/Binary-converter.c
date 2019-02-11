/*
  Name:hw3
  Copyright: 鄭少齊
  Author: 鄭少齊
  Date: 28/11/13 21:02
  Description:將輸入的10BIT以下二進制碼轉換成十進制碼及三進制碼
*/
#include <stdio.h>
#include <stdlib.h>

void line();
int main()
{
  int a,b,c,d,i;
  int g[10]={512,256,128,64,32,16,8,4,2,1};//二進制
  int h[7];//三進制 
  int f[10]={1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};//輸入數字砍成個位數
  printf("\t**************\n");
  printf("\t**進制轉換器**\n");
  printf("\t**************\n\n");
  line();
  printf("說明:\n\n將輸入的10BIT以下二進制碼轉換成十進制碼及三進制碼。 \n\n");
  start:
  line();
  i=0;b=0;
  int e[10]={0};
  printf("輸入ㄧ個10BIT以下的二進制資料。\n");
  scanf("%d",&a);//輸入數字並讀取
  for(d=0;d<10;d++)
  e[d]=(a-e[0]*f[0]-e[1]*f[1]-e[2]*f[2]-e[3]*f[3]-e[4]*f[4]-e[5]*f[5]-e[6]*f[6]-e[7]*f[7]-e[8]*f[8]-e[9]*f[9])/f[d];//把A各個位數刪減成個位數後ㄧ次存進E陣列
  for(d=0;d<10;d++)
  {           
                   if(e[d]>=2)
                   i=1;
                   if((a>1111111111)||(a<0))//整個字串大於1111111111或小於0或單一字元大於1都為無效輸入
                   i=1;                   
  }
  if(i==0)
  {
          for(d=0;d<10;d++)
          b=e[d]*g[d]+b;
          line();
          printf("十進制為 %d\n\n",b);
          for(c=1;c<=7;c++)
          {
            
               h[7-c]=b%3;
               b=b/3;
                     
          }
          line();
          printf("\n三進制為 ");
          for(d=0;d<7;d++)
          printf("%d",h[d]);
          printf("\n\n\n");
          printf("輸入 1 重新開始程式，輸入 0 結束程式。");
          scanf("%d",&i);
 }
 else printf("輸入資料不為2進制，請重新輸入。"); 
 printf("\n\n");
 if(i==1)
 goto start;//返回start 
 else if(i==0)
 {system("PAUSE");	
 return 0;}
}
void line()//列印分隔線 
{
     int a;
     for(a=0;a<35;a++)
                   {
                            printf("=");
                   }
     printf("\n\n");
     return 0;
} 

