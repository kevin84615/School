/*
  Name:hw3
  Copyright: �G�ֻ�
  Author: �G�ֻ�
  Date: 28/11/13 21:02
  Description:�N��J��10BIT�H�U�G�i��X�ഫ���Q�i��X�ΤT�i��X
*/
#include <stdio.h>
#include <stdlib.h>

void line();
int main()
{
  int a,b,c,d,i;
  int g[10]={512,256,128,64,32,16,8,4,2,1};//�G�i��
  int h[7];//�T�i�� 
  int f[10]={1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};//��J�Ʀr�妨�Ӧ��
  printf("\t**************\n");
  printf("\t**�i���ഫ��**\n");
  printf("\t**************\n\n");
  line();
  printf("����:\n\n�N��J��10BIT�H�U�G�i��X�ഫ���Q�i��X�ΤT�i��X�C \n\n");
  start:
  line();
  i=0;b=0;
  int e[10]={0};
  printf("��J����10BIT�H�U���G�i���ơC\n");
  scanf("%d",&a);//��J�Ʀr��Ū��
  for(d=0;d<10;d++)
  e[d]=(a-e[0]*f[0]-e[1]*f[1]-e[2]*f[2]-e[3]*f[3]-e[4]*f[4]-e[5]*f[5]-e[6]*f[6]-e[7]*f[7]-e[8]*f[8]-e[9]*f[9])/f[d];//��A�U�Ӧ�ƧR��Ӧ�ƫ᣸���s�iE�}�C
  for(d=0;d<10;d++)
  {           
                   if(e[d]>=2)
                   i=1;
                   if((a>1111111111)||(a<0))//��Ӧr��j��1111111111�Τp��0�γ�@�r���j��1�����L�Ŀ�J
                   i=1;                   
  }
  if(i==0)
  {
          for(d=0;d<10;d++)
          b=e[d]*g[d]+b;
          line();
          printf("�Q�i� %d\n\n",b);
          for(c=1;c<=7;c++)
          {
            
               h[7-c]=b%3;
               b=b/3;
                     
          }
          line();
          printf("\n�T�i� ");
          for(d=0;d<7;d++)
          printf("%d",h[d]);
          printf("\n\n\n");
          printf("��J 1 ���s�}�l�{���A��J 0 �����{���C");
          scanf("%d",&i);
 }
 else printf("��J��Ƥ���2�i��A�Э��s��J�C"); 
 printf("\n\n");
 if(i==1)
 goto start;//��^start 
 else if(i==0)
 {system("PAUSE");	
 return 0;}
}
void line()//�C�L���j�u 
{
     int a;
     for(a=0;a<35;a++)
                   {
                            printf("=");
                   }
     printf("\n\n");
     return 0;
} 

