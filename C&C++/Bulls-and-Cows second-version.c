/*
	Name: homework02.c
	Copyright: ��߰����Ĥ@��ޤj�� �q���P�q�T�u�{�t
	Author: �G�ֻ�
	Date: 10/12/16 16:46
	Description: �q�Q�i��Ʀr�C�������D
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main(int argc, char** argv[]) {
	int number, n3, n2, n1, n0;   //�H���Ʀr 
	int guess, g3, g2, g1, g0;    //�q�����Ʀr 
	int counter;                  //�ĴX���q�Ʀr 
	int a, b;
	char again;
	srand(time(NULL));  //�ϥιq�������m�ɶ��@���H���Ͳ����ؤl 
	do{
		do{
			number = rand()%(65244-4660+1) + 4660; //�q4660��65244�H���ͦ� 
			n3 = number/4096 % 16;  //�d�� 
			n2 = number/256 % 16;   //�ʦ� 
			n1 = number/16 % 16;    //�Q�� 
			n0 = number % 16;       //�Ӧ� 
		}while (n3==n2 || n3==n1 || n3==n0 || n2==n1 || n2==n0 || n1==n0);
		printf("�|��ƪ��H���Q�i���Ƭ�%x\n", number);
		counter = 1;                //�Ĥ@���q�Ʀr 
		do{
			do{
				printf("�A��%d ���q���@�ӥ|��ƪ��Q�i���ƼƦr���G", counter);
				scanf("%x", &guess);   //��J�q�����Ʀr 
				g3 = guess/4096 % 16;  //�d��
				g2 = guess/256 % 16;   //�ʦ�
				g1 = guess/16 % 16;    //�Q��
				g0 = guess % 16;       //�Ӧ�
			}while (g3==g2 || g3==g1 || g3==g0 || g2==g1 || g2==g0 || g1==g0);
			a = 0;
			b = 0;
			counter++;                 //�U�@���q�Ʀr 
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
			printf("�o�@���A�q�����G�� %dA%dB\n", a, b);
		}while (a!=4 || b!=0);
		printf("\n ���ߧA�q��F�A�Q�n�A���@�^�X��? (Y/N) ");
	do{
		again = getch();
	}while (again != 'Y' && again !='y' && again != 'N' && again != 'n');
	printf("%c\n\n", again);
	}while (again=='Y' || again=='y');
	system("PAUSE");
	return 0;
}
