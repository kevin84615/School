/*
  Name: hw06
  Copyright:�G�ֻ� 
  Author: �G�ֻ� 
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
  printf("�H���Ʀr�ͦ��ο�X��r�ɤ��A�еy��......\n");
  c=0;
  //�H������20�Ӷü� 
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
  //��X20�ӭȨ��r��
   fptr=fopen("mydate.txt","w");
   if(fptr!=NULL)
   {
                 
                 for(a=0;a<20;a++)
                 {
                                  fprintf(fptr,"x[%d]=%d\n",a,z[a]);
                 }
                 fclose(fptr);//���� 
   }
   printf("�H���Ʀr�ͦ��ο�X��r�ɧ���!!!\n");
   //Ū����r��    
    FILE *fo;         
    fo=fopen("mydate.txt","r");
    if(fo==NULL){
                 printf("Fail to open file out.txt!!");
                 system("PAUSE");
                 return 0;
                 }
    fclose(fo);//���� 
    printf("�H���Ʀr�ͦ���Ū����r�ɧ���!!!\n");
   printf("�H���Ʀr�ƧǤ��A�еy��......\n");
   //��w�ƧǪk(�Ѥj��p�Ƨ�)
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
   printf("�H���Ʀr�Ƨǧ���!!!\n");
   //�u�ʷj�M�k
   for(a=0;a<20;a++)
   printf("x[%d]=%d\n",a,x[a]);
   int f=0;
   printf("\n�H�u�ʷj�M�k�j�M�Ʀr�ƧǤ��A�еy��......\n");
   for(a=0;a<20;a++)
   {
                    if(x[a]==50)
                    f=a+1;
   }
   printf("�j�M�Ʀr����!!!\n");
   printf("�j�M���G:\n");
   if(f!=0)
   printf("�j�M�Ʀr 50 ���Ƨǲ� %d �Ӹ��!!!\n",f);
   if(f==0)
   printf("�j�M�Ʀr 50 ���b�ƧǤ�!!!\n");
   printf("\n�H�G���j�M�k�j�M�Ʀr�ƧǤ��A�еy��......\n");
   //�G���j�M�k
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
   printf("�j�M�Ʀr����!!!\n");
   printf("�j�M���G:\n");
   if(e==1)
   printf("�j�M�Ʀr 50 ���Ƨǲ� %d �Ӹ��!!!\n",mid+1);
   else printf("�j�M�Ʀr 50 ���b�ƧǤ�!!!\n");
  system("PAUSE");	
  return 0;
}
