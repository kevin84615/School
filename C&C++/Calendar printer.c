/*
	Name: homework04.c
	Copyright: ��߰����Ĥ@��ޤj�� �q���P�q�T�u�{�t
	Author: �G�ֻ�
	Date: 26/12/16 01:07
	Description: �~�䪺�C�L 
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{ int year, YEAR, C, Y, W, totalday, i,z;
printf("�п�J�褸�~��(>0)�G");
scanf("%d", &year); //��J�~�� 
while (year <= 0 )
{ printf("�L�Ħ褸�~��:%d\n", year);
printf("�п�J�褸�~��(>)�G");
scanf("%d", &year);
}
//�H�U��Zeller's ����
YEAR = year - 1;
C = YEAR / 100;
Y = YEAR % 100;
W = (C/4 - 2*C + Y + Y/4 - 1/5 + 1) % 7;
if (W < 0)
W = (W + 7) % 7;
//�H�U�N�Ӧ~���U�Ӥ�L�X 
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
printf("\n%38d �~%.2d ��\n", year, z);
printf("       �P����   �P���@    �P���G    �P���T    �P���|    �P����    �P����\n");
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

