/*
  Name: �G�ֻ� 
  Copyright: �G�ֻ� 
  Author: �G�ֻ� 
  Date: 14/11/13 14:37
  Description: ��J�@�ƭȡA�ӨM�w�@��C�ѥX�X��Ʀr
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
   printf("\t**�E�E���k��**\n");
   printf("\t**************\n\n");
   line();
   printf("����:\n\n��J�@�ƭȡA�ӨM�w�@��C�ѥX�X��Ʀr�C\n\n");
   line();
   printf("��J�@�ƭ�:\n");
   scanf("%d",&a);
   printf("\n"); 
   line();
   printf("��X:\n\n");
   

   while(hw2(a,n)<=9)                   /*�]�w�j��a,n<=9*/
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
     for(i=1;i<=9;i++)                 /*�]�w�j��i<=9,�C���[1*/ 
      {
             n=k;
             while(a>0)
             {
                    if(n<=9)
                    {
                           printf("%d * %d = %d",n,i,n*i);    /*�C�L�h�֭��W�h��*/
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
void line()                                   /*�C�L���j�u*/
{
     int a;
     for(a=0;a<35;a++)
                   {
                            printf("=");
                   }
     printf("\n\n");
} 
