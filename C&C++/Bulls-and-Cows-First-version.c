/*
  Name: �q�Ʀr�C��
  Copyright: �G�ֻ� 
  Author: �G�ֻ�
  Date: 05/12/13 02:35
  Description: ���׬����P��4�ӼƦr���ƦC�զX�A�q4�Ӥ��P���Ʀr�A�Y�Ʀr�P��m�ۦP�h��A�A�Y�Ʀr�ۦP��m���P�h��B
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//�B�z�ɶ�������
void line();
int main()
{
  int a,d,e,f,g,h,i,j,k,open,l; //�ܼ� 
  int b[4];//���� 
  int c[4];//����
  char z[4];
  start:
   printf("\t**************\n");
   printf("\t**�q�Ʀr�C��**\n");
   printf("\t**************\n\n");
   line();
   printf("����:\n\n���׬����P��4�ӼƦr���ƦC�զX�A�q4�Ӥ��P���Ʀr�A�Y�Ʀr�P��m�ۦP�h��A�A�Y�Ʀr�ۦP��m���P�h��B�A���֨ӬD�Ԧۤv�@�U�a�I(�q�`6-8���i�H���T�q�X,�d��1234~9876)\n\n");
   line();
   i=1;
   printf("����Ʀr���A�е���...\n");
  while(i==1)
  {
              j=0;
              srand(time(NULL));//�H�q���ɶ��w�q�üƨ�� 
              for(d=0;d<4;d++)//���|�ӼƦr 
              c[d]=(rand()%10);//0~9���@�ӼƦr 
              for(d=0;d<4;d++)//�H�U�j��O�קK������Ʀr���� 
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
  printf("�Ʀr�������...\n");
  f=0;
  k=c[0]*1000+c[1]*100+c[2]*10+c[3];
  while(f<=3)
  {          

             int x=0;//�w�qA=0 
             int y=0;
             a=0;
             open=1;
             printf("\n�п�J�|�Ӫ��ԧB�Ʀr\n");
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
                              if((l>9876)||(l<1234))//�d��1234~9876 
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
                             if(b[d]==c[d])//�P�_��J�Ʀr�M��m�O�_���T
                             x=x+1;//�ŦXif����A�h+1 
                             for(e=0;e<4;e++)
                             {
                                             if(e!=d)
                                             if(b[d]==c[e])//�P�_��J�Ʀr�O�_���T (�Ʀr�M��m�ҥ��T���ä��]�A�b��) 
                                             y=y+1;//�ŦXif����B�h+1 
                                              
                             }
                          }
                          printf("%d A %d B\n",x,y);
             }
             else printf("��J���~\n");
             f=x;         
  }           
  printf("\n\n����F!! ��J 1 �A���@���C ��J 0 �����C���C\n");
  scanf("%d",&g);
  if(g==1)
  goto start;   //���J��1�ɪ�^start 
  else
  printf("\nBYE~~BYE!!!\n");  //���J��0�h���BYE BYE 
  system("pause");	
  return 0;
}
void line()     //�L�X���j�u 
{
     int a;
     for(a=0;a<55;a++)
                   {
                            printf("=");
                   }
     printf("\n\n");
     return 0;
} 

