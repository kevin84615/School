/*
  Name: 0251024
  Copyright: �G�ֻ� 
  Author: �G�ֻ� 
  Date: 30/03/14 22:06
  Description: ����ɮפ�����r�[�K�P�ѱK 
*/
#include<stdio.h>
#include<stdlib.h>
FILE *mycypher,*mydecry,*myplane;
char myp,myc,nextc,nextp,nexta;

int main()
{
	myplane=fopen("myplane.txt","rt");//Ū��myplane.txt 
	mycypher=fopen("mycypher.txt","w");//�g�Jmycypher.txt
	
    
    printf("==============================myplane.txt��󤺮e===============================\n");
	while(myp!=EOF)//Ū���ɮר쵲������ 
	{
		myp=fgetc(myplane);//�@�Ӧr���@�Ӧr��Ū�� 
		printf("%c",myp);
		if(myp==13||myp==10)//Ū���촫��r�� 
			myc=myp;//���s�X 
		else
		    myc=((113*(myp-32)+45)%94)+32;//�s�X 
		fputc(myc,mycypher);//�@�Ӧr���@�Ӧr���g�J��� 
	}
	fclose(myplane);//���� 
	fclose(mycypher);//����
	
    
    printf("\n==============================mycypher.txt�[�K�L��==============================\n");
	mycypher=fopen("mycypher.txt","rt");//Ū��mycypher.txt 
	mydecry=fopen("mydecry.txt","w");//�g�Jmydecry.txt
	while(nextc!=EOF)//Ū���ɮר쵲������
	{
		nextc=fgetc(mycypher);//�@�Ӧr���@�Ӧr��Ū��
		printf("%c",nextc);
		if(nextc==13||nextc==10)//Ū���촫��r��
			nextp=nextc;//���ѽX
		else
		    nextp=((5*(nextc-32)+57)%94)+32;//�ѽX 
		fputc(nextp,mydecry);//�@�Ӧr���@�Ӧr���g�J��� 
	}
	fclose(mycypher);//����
	fclose(mydecry);//����
	
    
    printf("\n===============================mydecry.txt�ѱK�L��==============================\n");
	mydecry=fopen("mydecry.txt","rt");//Ū��mydecry.txt 
	while(nexta!=EOF)//Ū���ɮר쵲������
	{
		nexta=fgetc(mydecry);//�@�Ӧr���@�Ӧr��Ū��
		printf("%c",nexta);//�L�X���e 
	}
	printf("\n");
	
    system("PAUSE");
	return 0;
}
