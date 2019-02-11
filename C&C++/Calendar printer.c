/*
	Name: homework04.c
	Copyright: 國立高雄第一科技大學 電腦與通訊工程系
	Author: 鄭少齊
	Date: 26/12/16 01:07
	Description: 年曆的列印 
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{ int year, YEAR, C, Y, W, totalday, i,z;
printf("請輸入西元年份(>0)：");
scanf("%d", &year); //輸入年份 
while (year <= 0 )
{ printf("無效西元年份:%d\n", year);
printf("請輸入西元年份(>)：");
scanf("%d", &year);
}
//以下為Zeller's 公式
YEAR = year - 1;
C = YEAR / 100;
Y = YEAR % 100;
W = (C/4 - 2*C + Y + Y/4 - 1/5 + 1) % 7;
if (W < 0)
W = (W + 7) % 7;
//以下將該年的各個月印出 
for(z=1;z<13;z++){
switch (z)
{ case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12: totalday = 31;
break;
case 4:
case 6:
case 9:
case 11: totalday = 30;
break;
case 2: if (year%400 == 0 || (year%4 == 0 && year%100 != 0))
totalday = 29;
else
totalday = 28;
break;
}
printf("\n%38d 年%.2d 月\n", year, z);
printf("       星期日   星期一    星期二    星期三    星期四    星期五    星期六\n");
for (i = 1; i <= W; i++)
printf("%10s", " ");
for (i = 1; i <= totalday; i++)
{ printf("%10d", i);
W++;
if (W == 7)
{ printf("\n");
W = 0;
}
}
}
printf("\n\n");
system("PAUSE");
return 0;
}

