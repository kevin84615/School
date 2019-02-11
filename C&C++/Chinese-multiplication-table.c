/*
  Name: 鄭少齊 
  Copyright: 鄭少齊 
  Author: 鄭少齊 
  Date: 14/11/13 14:37
  Description: 輸入一數值，來決定一橫列書出幾欄數字
*/

#include <stdio.h>
#include <stdlib.h>
int hw2(int,int);
void line();
int j;
int main()
{
   int a,b,n,i;
   n=1;
   printf("\t**************\n");
   printf("\t**九九乘法表**\n");
   printf("\t**************\n\n");
   line();
   printf("說明:\n\n輸入一數值，來決定一橫列書出幾欄數字。\n\n");
   line();
   printf("輸入一數值:\n");
   scanf("%d",&a);
   printf("\n"); 
   line();
   printf("輸出:\n\n");
   

   while(hw2(a,n)<=9)                   /*設定迴圈a,n<=9*/
   {
           
           n=j; 
           printf("\n");
                  
   }
  printf("\n");
  system("PAUSE");	
  return 0;
}

int hw2(int a,int n)                     
{
     int b,i,k;
     b=a;
     k=n;
     for(i=1;i<=9;i++)                 /*設定迴圈i<=9,每次加1*/ 
      {
             n=k;
             while(a>0)
             {
                    if(n<=9)
                    {
                           printf("%d * %d = %d",n,i,n*i);    /*列印多少乘上多少*/
                           printf("\t");
                           n++;
                    }
                    a--;   
             }
             printf("\n");
             a=b;
      }
    j=n;
    return j; 
}
void line()                                   /*列印分隔線*/
{
     int a;
     for(a=0;a<35;a++)
                   {
                            printf("=");
                   }
     printf("\n\n");
} 
