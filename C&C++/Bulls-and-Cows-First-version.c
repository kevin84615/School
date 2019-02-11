/*
  Name: 猜數字遊戲
  Copyright: 鄭少齊 
  Author: 鄭少齊
  Date: 05/12/13 02:35
  Description: 答案為不同的4個數字的排列組合，猜4個不同的數字，若數字與位置相同則為A，若數字相同位置不同則為B
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//處理時間日期函數
void line();
int main()
{
  int a,d,e,f,g,h,i,j,k,open,l; //變數 
  int b[4];//答案 
  int c[4];//答案
  char z[4];
  start:
   printf("\t**************\n");
   printf("\t**猜數字遊戲**\n");
   printf("\t**************\n\n");
   line();
   printf("說明:\n\n答案為不同的4個數字的排列組合，猜4個不同的數字，若數字與位置相同則為A，若數字相同位置不同則為B，趕快來挑戰自己一下吧！(通常6-8次可以正確猜出,範圍1234~9876)\n\n");
   line();
   i=1;
   printf("抽取數字中，請等候...\n");
  while(i==1)
  {
              j=0;
              srand(time(NULL));//以電腦時間定義亂數函數 
              for(d=0;d<4;d++)//取四個數字 
              c[d]=(rand()%10);//0~9取一個數字 
              for(d=0;d<4;d++)//以下迴圈是避免抽取的數字重複 
              {
                  for(h=3;h>=0;h--)
                  {
                        if(d!=h)
                        if(c[d]==c[h])
                        {
                           j=1;
                        }
                        
                  }
              }   
              if(c[0]==0)
              j=1;
              if(j!=1)
              i=0;
              
  }
  printf("數字抽取完畢...\n");
  f=0;
  k=c[0]*1000+c[1]*100+c[2]*10+c[3];
  while(f<=3)
  {          

             int x=0;//定義A=0 
             int y=0;
             a=0;
             open=1;
             printf("\n請輸入四個阿拉伯數字\n");
             gets(z);
             while(z[a]!='\0')
             {
                              if((z[a]>'9')&&(z[a]<'0'))
                              open=0;
                              a++;
             }
             
             if(a==4)
             {
                              for(d=0;d<4;d++)
                              b[d]=z[d]-'0';
                              l=b[0]*1000+b[1]*100+b[2]*10+b[3];
                              if((l>9876)||(l<1234))//範圍1234~9876 
                              open=0;
                              for(d=0;d<4;d++)
                                  {
                                     for(h=3;h>=0;h--)
                                         {
                                            if(d!=h)
                                              {
                                                    if(c[d]==c[h])
                                                      {
                                                                  open=0;
                                                      }
                                              }
                                          }
                                   }   
             }
             if((open==1)&&(a==4)) 
             {            
                          c[0]=k/1000;
                          c[1]=(k-c[0]*1000)/100;
                          c[2]=(k-c[0]*1000-c[1]*100)/10;
                          c[3]=(k-c[0]*1000-c[1]*100-c[2]*10);
                          for(d=0;d<4;d++)
                          {
                             if(b[d]==c[d])//判斷輸入數字和位置是否正確
                             x=x+1;//符合if條件的A則+1 
                             for(e=0;e<4;e++)
                             {
                                             if(e!=d)
                                             if(b[d]==c[e])//判斷輸入數字是否正確 (數字和位置皆正確的並不包括在內) 
                                             y=y+1;//符合if條件的B則+1 
                                              
                             }
                          }
                          printf("%d A %d B\n",x,y);
             }
             else printf("輸入錯誤\n");
             f=x;         
  }           
  printf("\n\n答對了!! 輸入 1 再玩一次。 輸入 0 結束遊戲。\n");
  scanf("%d",&g);
  if(g==1)
  goto start;   //當輸入為1時返回start 
  else
  printf("\nBYE~~BYE!!!\n");  //當輸入為0則顯示BYE BYE 
  system("pause");	
  return 0;
}
void line()     //印出分隔線 
{
     int a;
     for(a=0;a<55;a++)
                   {
                            printf("=");
                   }
     printf("\n\n");
     return 0;
} 

