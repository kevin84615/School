/*
  Name: hw5
  Copyright: �G�ֻ� 
  Author: �G�ֻ�
  Date: 19/12/13 02:30
  Description: �D�ƾǨ�ƿn���������
*/

#include "stdio.h" 
#include "math.h" 
float pi=3.1415926;//�k=3.1415926
double f1(double x) //f1(x)
{    
     return 10*sin(x/2);  
}
double f2(double x) //f2(x)
{    
     return 20-10/pi*x;  
}
double f3(double x) //f3(x)
{    
     double a;
     a=0-sin(x/2);
     return a;  
}  
double rt(double a,double b,int n,int z) //�x�Ϊk�Ƶ{��
{   
    double h;   
    double fx;   
    double x;   
    int i;      
    double sum=0; 
    h=fabs(a-b)/n;   
    x=a;
    switch(z)
    {
             case 1:    
                  for(i=0;i<n;i++)   
                    {    
                         fx=f1(x+i*h+h/2);    
                         sum=sum+fx;    
                    }
             break;
             case 2:
                  for(i=0;i<n;i++)   
                    {    
                         fx=f2(x+i*h+h/2);    
                         sum=sum+fx;    
                    }
             break;
             case 3:
                  for(i=0;i<n;i++)   
                    {    
                         fx=f3(x+i*h+h/2);    
                         sum=sum+fx;    
                    }
             break;
    }     
    return fabs(sum*h);  
}
double tp(double a,double b,int n,int z) //��Ϊk�Ƶ{�� 
{   
    double h;   
    double fx;   
    double x;   
    int i;      
    double sum=0; 
    h=fabs(a-b)/n;   
    x=a;
    switch(z)
    {
             case 1:    
                  for(i=1;i<(n-1);i++)   
                    {    
                         fx=2*f1(x+i*h);    
                         sum=sum+fx;    
                    }
                    sum=sum+f1(a)+f1(b);
             break;
             case 2:
                  for(i=1;i<(n-1);i++)   
                    {    
                         fx=2*f2(x+i*h);    
                         sum=sum+fx;    
                    }
                    sum=sum+f2(a)+f2(b);
             break;
             case 3:
                  for(i=1;i<(n-1);i++)   
                    {    
                         fx=2*f3(x+i*h);    
                         sum=sum+fx;    
                    }
                    sum=sum+f3(a)+f3(b);
             break;
    }     
    return fabs(sum*h/2);  
}  
void main() //�U���{�����C�L�X���G 
{   
    double a;   
    double b;   
    double fx,fxo=0;  
    a=0;   
    b=pi;   
    fx=rt(a,b,5000,1);     
    printf("�x�Ϊk 5000�� f1=%lf\n",fx); 
    fxo=fx+fxo;
    a=pi;   
    b=2*pi;   
    fx=rt(a,b,5000,2);     
    printf("�x�Ϊk 5000�� f2=%lf\n" ,fx);
    fxo=fx+fxo;
    a=0;   
    b=2*pi;   
    fx=rt(a,b,5000,3);     
    printf("�x�Ϊk 5000�� f3=%lf\n" ,fx);
    fxo=fx+fxo;
    printf("�x�Ϊk 5000�� f1+f2+f3=%lf\n" ,fxo);
    fxo=0;
    a=0;   
    b=pi;   
    fx=rt(a,b,10000,1);     
    printf("�x�Ϊk 10000�� f1=%lf\n",fx); 
    fxo=fx+fxo;
    a=pi;   
    b=2*pi;   
    fx=rt(a,b,10000,2);     
    printf("�x�Ϊk 10000�� f2=%lf\n" ,fx);
    fxo=fx+fxo;
    a=0;   
    b=2*pi;   
    fx=rt(a,b,10000,3);     
    printf("�x�Ϊk 10000�� f3=%lf\n" ,fx);
    fxo=fx+fxo;
    printf("�x�Ϊk 10000�� f1+f2+f3=%lf\n" ,fxo);
    fxo=0;
    a=0;   
    b=pi;   
    fx=tp(a,b,5000,1);     
    printf("��Ϊk 5000�� f1=%lf\n" ,fx);
    fxo=fx+fxo;
    a=pi;   
    b=2*pi;   
    fx=tp(a,b,5000,2);     
    printf("��Ϊk 5000�� f2=%lf\n",fx); 
    fxo=fx+fxo;
    a=0;   
    b=2*pi;   
    fx=tp(a,b,5000,3);     
    printf("��Ϊk 5000�� f3=%lf\n" ,fx);
    fxo=fx+fxo;
    printf("��Ϊk 5000�� f1+f2+f3=%lf\n" ,fxo);
        fxo=0;
    a=0;   
    b=pi;   
    fx=tp(a,b,10000,1);     
    printf("��Ϊk 10000�� f1=%lf\n" ,fx);
    fxo=fx+fxo;
    a=pi;   
    b=2*pi;   
    fx=tp(a,b,10000,2);     
    printf("��Ϊk 10000�� f2=%lf\n",fx); 
    fxo=fx+fxo;
    a=0;   
    b=2*pi;   
    fx=tp(a,b,10000,3);     
    printf("��Ϊk 10000�� f3=%lf\n" ,fx);
    fxo=fx+fxo;
    printf("�x�Ϊk 10000�� f1+f2+f3=%lf\n" ,fxo);
    system("pause"); 
}
