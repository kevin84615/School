/*
  Name: hw06
  Copyright:鄭少齊 
  Author: 鄭少齊 
  Date: 02/01/14 23:05
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a,b,c,d,i,v;
    int z[20];
    int y[20][4];
    int x[20];
    char w[80];
    FILE *fptr;
  start:
  printf("隨機數字生成及輸出文字檔中，請稍候......\n");
  c=0;
  //隨機產生20個亂數 
  srand(time(0));
  for(a=0;a<20;a++)
  {
                   
                   z[a]=rand()%100+1;
                   for(b=0;b<20;b++)
                   {
                                    if(a!=b)
                                    {
                                            
                                            if(z[a]==z[b])
                                            c=1;
                                            else
                                            c=0;
                                    }
                                    if(c==1)
                                    break;
                   }
                   if(c==1)
                   {
                           a--;
                           srand(time(0));
                   }
  }
  //輸出20個值到文字檔
   fptr=fopen("mydate.txt","w");
   if(fptr!=NULL)
   {
                 
                 for(a=0;a<20;a++)
                 {
                                  fprintf(fptr,"x[%d]=%d\n",a,z[a]);
                 }
                 fclose(fptr);//關閉 
   }
   printf("隨機數字生成及輸出文字檔完畢!!!\n");
   //讀取文字檔    
    FILE *fo;         
    fo=fopen("mydate.txt","r");
    if(fo==NULL){
                 printf("Fail to open file out.txt!!");
                 system("PAUSE");
                 return 0;
                 }
    fclose(fo);//關閉 
    printf("隨機數字生成及讀取文字檔完畢!!!\n");
   printf("隨機數字排序中，請稍候......\n");
   //氣泡排序法(由大到小排序)
   for(a=0;a<20;a++)
   x[a]=z[a];
   for(a=0;a<20;a++)
   {
                    d=0;
                    for(b=0;b<20;b++)
                    {
                                     if(z[a]<z[b])
                                     d++;
                                     
                    }
                    x[d]=z[a];     
   }
   printf("隨機數字排序完成!!!\n");
   //線性搜尋法
   for(a=0;a<20;a++)
   printf("x[%d]=%d\n",a,x[a]);
   int f=0;
   printf("\n以線性搜尋法搜尋數字排序中，請稍候......\n");
   for(a=0;a<20;a++)
   {
                    if(x[a]==50)
                    f=a+1;
   }
   printf("搜尋數字完畢!!!\n");
   printf("搜尋結果:\n");
   if(f!=0)
   printf("搜尋數字 50 位於排序第 %d 個資料!!!\n",f);
   if(f==0)
   printf("搜尋數字 50 不在排序中!!!\n");
   printf("\n以二分搜尋法搜尋數字排序中，請稍候......\n");
   //二分搜尋法
   int e,lo,hi,mid;
   lo=0;
   hi=19;
   e=0;
   while(lo<=hi)
   {
                mid=(lo+hi)/2;
                if(x[mid]==50)
                e=1;
                else if(x[mid]<50)
                hi=mid-1;
                else if(x[mid]>50)
                lo=mid+1;
                if(e==1)
                break;       
   }
   printf("搜尋數字完畢!!!\n");
   printf("搜尋結果:\n");
   if(e==1)
   printf("搜尋數字 50 位於排序第 %d 個資料!!!\n",mid+1);
   else printf("搜尋數字 50 不在排序中!!!\n");
  system("PAUSE");	
  return 0;
}
