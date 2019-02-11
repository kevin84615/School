/*
  Name: 0251024
  Copyright: 鄭少齊 
  Author: 鄭少齊 
  Date: 30/03/14 22:06
  Description: 資料檔案內的文字加密與解密 
*/
#include<stdio.h>
#include<stdlib.h>
FILE *mycypher,*mydecry,*myplane;
char myp,myc,nextc,nextp,nexta;

int main()
{
	myplane=fopen("myplane.txt","rt");//讀取myplane.txt 
	mycypher=fopen("mycypher.txt","w");//寫入mycypher.txt
	
    
    printf("==============================myplane.txt文件內容===============================\n");
	while(myp!=EOF)//讀取檔案到結束為止 
	{
		myp=fgetc(myplane);//一個字元一個字元讀取 
		printf("%c",myp);
		if(myp==13||myp==10)//讀取到換行字元 
			myc=myp;//不編碼 
		else
		    myc=((113*(myp-32)+45)%94)+32;//編碼 
		fputc(myc,mycypher);//一個字元一個字元寫入文件 
	}
	fclose(myplane);//關檔 
	fclose(mycypher);//關檔
	
    
    printf("\n==============================mycypher.txt加密過後==============================\n");
	mycypher=fopen("mycypher.txt","rt");//讀取mycypher.txt 
	mydecry=fopen("mydecry.txt","w");//寫入mydecry.txt
	while(nextc!=EOF)//讀取檔案到結束為止
	{
		nextc=fgetc(mycypher);//一個字元一個字元讀取
		printf("%c",nextc);
		if(nextc==13||nextc==10)//讀取到換行字元
			nextp=nextc;//不解碼
		else
		    nextp=((5*(nextc-32)+57)%94)+32;//解碼 
		fputc(nextp,mydecry);//一個字元一個字元寫入文件 
	}
	fclose(mycypher);//關檔
	fclose(mydecry);//關檔
	
    
    printf("\n===============================mydecry.txt解密過後==============================\n");
	mydecry=fopen("mydecry.txt","rt");//讀取mydecry.txt 
	while(nexta!=EOF)//讀取檔案到結束為止
	{
		nexta=fgetc(mydecry);//一個字元一個字元讀取
		printf("%c",nexta);//印出內容 
	}
	printf("\n");
	
    system("PAUSE");
	return 0;
}
