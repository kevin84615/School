/*
  Name: hw1
  Copyright:�G�ֻ� 
  Author: �G�ֻ� 
  Date: 16/10/13 00:59
  Description: �ϥ� int float double �T�ث��A��XN!���� 
*/

#include <cstdlib>
#include <iostream>

int main()
{
  unsigned int a,c;
  float b=1;
  double d=1;
  c=1;
  for(a=1;a<=100;a++)
  {
                  c=a*c;
                  printf("�Hint���A��� %3.0d ! �� %30.0d\n",a,c);
  }
  for(a=1;a<=100;a++)
  {
                  b=a*b;
                  printf("�Hfloat���A��� %3.0d ! �� %50.0f\n",a,b);
  }
  for(a=1;a<=100;a++)
  {
                  d=a*d;
                  printf("�Hdouble���A��� %3.0d ! �� %50.0lf\n",a,d);
  }
  system("PAUSE");	
  return 0;
}
