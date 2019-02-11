/*
  Name: 0251024hw1
  Copyright: 0251024
  Author: 鄭少齊 
  Date: 13/03/14 16:53
  Description: Pointer and File
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *data_txt;
FILE *descendingbubble_txt;
FILE *ascendingbubble_txt;
int num,i;
void bubble(int *,int,int (*)(int,int));
void swap(int *,int *);
void line();
int ascending(int,int);
int descending(int,int);

int main(void)
{
    line();
    printf("請輸入你想要排序的數量 :\n");
    printf("(例如:座號24，請輸入24，便會產生24個數字)\n");
    printf("※請注意亂數產生範圍為1-1000，排序數量不可超過1000※\n");
	scanf("%d",&num);
	/******************輸入數值******************/
    line();
    printf("您輸入了%d，開始產生%d個亂數\n",num,num); 
	/******************配置動態記憶體******************/
	int *data=(int*)malloc(sizeof(int)*num);
	/******************亂數產生******************/
	srand(clock());
	printf("亂數產生中...\n");	
	for(i=0;i<num;i++)
    *(data+i)=rand()%1000;
	printf("產生完畢!\n");

	printf("*********************data.txt執行中********************\n");
	/******************清除data.txt的內容******************/
	data_txt=fopen("data.txt","wt");
	printf("清除data.txt資料中...\n");
    for(i=0;i<1000;i++)	
    {
		fprintf(data_txt,"%d\n","");
    }
    fclose(data_txt); 
	printf("清除完成!\n");		
	/******************數值寫入data.txt******************/ 
	data_txt=fopen("data.txt","wt");	
	printf("寫入data.txt中...\n");
    for(i=0;i<num;i++)	
    {
		fprintf(data_txt,"%d\n",*(data+i));
    }
    fclose(data_txt); 
	printf("寫入完成!\n");
	/******************讀取data.txt******************/  
	data_txt=fopen("data.txt","rt");
	printf("讀取data.txt中...\n");
    for(i=0;i<num;i++)	
    {
		fscanf(data_txt,"%d\n",data+i);
    }
    fclose(data_txt); 
	printf("讀取完成!\n");
	/*☆★☆★☆★☆★☆★降冪氣泡排序☆★☆★☆★☆★☆★☆★*/ 
	printf("**********************降冪氣泡排序*********************\n");
	bubble(data,num,descending);	
	printf("降冪排列 :\n");
	for(i=0;i<num;i++)
    printf("%d\n",*(data+i));
	/******************清除descending bubble.txt的內容******************/
	printf("**************descending bubble.txt執行中**************\n");
	printf("清除descending bubble.txt資料中...\n");
	descendingbubble_txt=fopen("descending bubble.txt","wt");
    for(i=0;i<1000;i++)	
    {
		fprintf(descendingbubble_txt,"%d\n","");
    }
    fclose(descendingbubble_txt); 
	printf("清除完成!\n");	
	/******************數值寫入descending bubble.txt******************/
	descendingbubble_txt=fopen("descending bubble.txt","wt");
	printf("寫入descending bubble.txt中...\n");
    for(i=0;i<num;i++)	
    {
		fprintf(descendingbubble_txt,"%d\n",*(data+i));
    }
    fclose(descendingbubble_txt); 
	printf("寫入完成!\n");
	/*☆★☆★☆★☆★☆★升冪氣泡排序☆★☆★☆★☆★☆★☆★*/
	printf("**********************降冪氣泡排序*********************\n"); 	
	bubble(data,num,ascending);
	printf("升冪排列 :\n");
	for(i=0;i<num;i++)
    printf("%d\n",*(data+i));
	/******************清除ascending bubble.txt的內容******************/
	printf("**************ascending bubble.txt執行中**************\n");
	printf("清除ascending bubble.txt資料中...\n");
	ascendingbubble_txt=fopen("ascending bubble.txt","wt");

    for(i=0;i<1000;i++)	
    {
		fprintf(ascendingbubble_txt,"%d\n","");
    }
    fclose(ascendingbubble_txt); 
	printf("清除完成!\n");	
	/******************數值寫入ascending bubble.txt******************/  
	ascendingbubble_txt=fopen("ascending bubble.txt","wt");	
	printf("寫入ascending bubble.txt中...\n");
    for(i=0;i<num;i++)	
    {
		fprintf(ascendingbubble_txt,"%d\n",*(data+i));
    }
    fclose(ascendingbubble_txt); 
	printf("寫入完成!\n");	    
	printf("\n");
	line();
	/******************釋放動態配置記憶體******************/
	free(data);
	system("PAUSE");
	return 0;
}

void bubble(int *array,int size,int (*compare)(int a,int b))
{
	int j,pair=size-1;
	for(pair;pair>0;--pair)
	{
		for(j=0;j<pair;j++)
		{
			if((*compare)(*(array+j),*(array+j+1)))
			    swap(array+j,array+j+1);
		}
	}
}
void swap(int *aptr,int *bptr)
{
	int temp;
	temp=*aptr;
	*aptr=*bptr;
	*bptr=temp;
}
void line()
{
     int a;
     for(a=0;a<55;a++)
                   {
                            printf("=");
                   }
     printf("\n\n");
     return 0;
} 
int ascending(int a,int b)
{
	return a>b;
}
int descending(int a,int b)
{
	return a<b;
}
