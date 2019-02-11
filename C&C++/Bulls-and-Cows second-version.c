/*
	Name: homework02.c
	Copyright: 國立高雄第一科技大學 電腦與通訊工程系
	Author: 鄭少齊
	Date: 10/12/16 16:46
	Description: 猜十進制數字遊戲的問題
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main(int argc, char** argv[]) {
	int number, n3, n2, n1, n0;   //隨機數字 
	int guess, g3, g2, g1, g0;    //猜測的數字 
	int counter;                  //第幾次猜數字 
	int a, b;
	char again;
	srand(time(NULL));  //使用電腦的內置時間作為隨機生產的種子 
	do{
		do{
			number = rand()%(65244-4660+1) + 4660; //從4660到65244隨機生成 
			n3 = number/4096 % 16;  //千位 
			n2 = number/256 % 16;   //百位 
			n1 = number/16 % 16;    //十位 
			n0 = number % 16;       //個位 
		}while (n3==n2 || n3==n1 || n3==n0 || n2==n1 || n2==n0 || n1==n0);
		printf("四位數的隨機十進制整數為%x\n", number);
		counter = 1;                //第一次猜數字 
		do{
			do{
				printf("你第%d 次猜的一個四位數的十進制整數數字為：", counter);
				scanf("%x", &guess);   //輸入猜測的數字 
				g3 = guess/4096 % 16;  //千位
				g2 = guess/256 % 16;   //百位
				g1 = guess/16 % 16;    //十位
				g0 = guess % 16;       //個位
			}while (g3==g2 || g3==g1 || g3==g0 || g2==g1 || g2==g0 || g1==g0);
			a = 0;
			b = 0;
			counter++;                 //下一次猜數字 
			if (n3==g3)
			a++;
			if (n2==g2)
			a++;
			if (n1==g1)
			a++;
			if (n0==g0)
			a++;
			if (n3==g2 || n3==g1 || n3==g0)
			b++;
			if (n2==g3 || n2==g1 || n2==g0)
			b++;
			if (n1==g3 || n1==g2 || n1==g0)
			b++;
			if (n0==g3 || n0==g2 || n0==g1)
			b++;
			printf("這一次你猜的結果為 %dA%dB\n", a, b);
		}while (a!=4 || b!=0);
		printf("\n 恭喜你猜對了，想要再玩一回合嗎? (Y/N) ");
	do{
		again = getch();
	}while (again != 'Y' && again !='y' && again != 'N' && again != 'n');
	printf("%c\n\n", again);
	}while (again=='Y' || again=='y');
	system("PAUSE");
	return 0;
}
