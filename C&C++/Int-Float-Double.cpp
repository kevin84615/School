/*
  Name: hw1
  Copyright:鄭少齊 
  Author: 鄭少齊 
  Date: 16/10/13 00:59
  Description: 使用 int float double 三種型態輸出N!的值 
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
                  printf("以int型態表示 %3.0d ! 為 %30.0d\n",a,c);
  }
  for(a=1;a<=100;a++)
  {
                  b=a*b;
                  printf("以float型態表示 %3.0d ! 為 %50.0f\n",a,b);
  }
  for(a=1;a<=100;a++)
  {
                  d=a*d;
                  printf("以double型態表示 %3.0d ! 為 %50.0lf\n",a,d);
  }
  system("PAUSE");	
  return 0;
}
