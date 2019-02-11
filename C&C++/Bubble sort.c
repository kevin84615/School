/*
  Name: 0251024hw1
  Copyright: 0251024
  Author: �G�ֻ� 
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
    printf("�п�J�A�Q�n�ƧǪ��ƶq :\n");
    printf("(�Ҧp:�y��24�A�п�J24�A�K�|����24�ӼƦr)\n");
    printf("���Ъ`�N�üƲ��ͽd��1-1000�A�ƧǼƶq���i�W�L1000��\n");
	scanf("%d",&num);
	/******************��J�ƭ�******************/
    line();
    printf("�z��J�F%d�A�}�l����%d�Ӷü�\n",num,num); 
	/******************�t�m�ʺA�O����******************/
	int *data=(int*)malloc(sizeof(int)*num);
	/******************�üƲ���******************/
	srand(clock());
	printf("�üƲ��ͤ�...\n");	
	for(i=0;i<num;i++)
    *(data+i)=rand()%1000;
	printf("���ͧ���!\n");

	printf("*********************data.txt���椤********************\n");
	/******************�M��data.txt�����e******************/
	data_txt=fopen("data.txt","wt");
	printf("�M��data.txt��Ƥ�...\n");
    for(i=0;i<1000;i++)	
    {
		fprintf(data_txt,"%d\n","");
    }
    fclose(data_txt); 
	printf("�M������!\n");		
	/******************�ƭȼg�Jdata.txt******************/ 
	data_txt=fopen("data.txt","wt");	
	printf("�g�Jdata.txt��...\n");
    for(i=0;i<num;i++)	
    {
		fprintf(data_txt,"%d\n",*(data+i));
    }
    fclose(data_txt); 
	printf("�g�J����!\n");
	/******************Ū��data.txt******************/  
	data_txt=fopen("data.txt","rt");
	printf("Ū��data.txt��...\n");
    for(i=0;i<num;i++)	
    {
		fscanf(data_txt,"%d\n",data+i);
    }
    fclose(data_txt); 
	printf("Ū������!\n");
	/*��������������������������w�Ƨǡ�����������������������*/ 
	printf("**********************������w�Ƨ�*********************\n");
	bubble(data,num,descending);	
	printf("�����ƦC :\n");
	for(i=0;i<num;i++)
    printf("%d\n",*(data+i));
	/******************�M��descending bubble.txt�����e******************/
	printf("**************descending bubble.txt���椤**************\n");
	printf("�M��descending bubble.txt��Ƥ�...\n");
	descendingbubble_txt=fopen("descending bubble.txt","wt");
    for(i=0;i<1000;i++)	
    {
		fprintf(descendingbubble_txt,"%d\n","");
    }
    fclose(descendingbubble_txt); 
	printf("�M������!\n");	
	/******************�ƭȼg�Jdescending bubble.txt******************/
	descendingbubble_txt=fopen("descending bubble.txt","wt");
	printf("�g�Jdescending bubble.txt��...\n");
    for(i=0;i<num;i++)	
    {
		fprintf(descendingbubble_txt,"%d\n",*(data+i));
    }
    fclose(descendingbubble_txt); 
	printf("�g�J����!\n");
	/*���������������������ɾ���w�Ƨǡ�����������������������*/
	printf("**********************������w�Ƨ�*********************\n"); 	
	bubble(data,num,ascending);
	printf("�ɾ��ƦC :\n");
	for(i=0;i<num;i++)
    printf("%d\n",*(data+i));
	/******************�M��ascending bubble.txt�����e******************/
	printf("**************ascending bubble.txt���椤**************\n");
	printf("�M��ascending bubble.txt��Ƥ�...\n");
	ascendingbubble_txt=fopen("ascending bubble.txt","wt");

    for(i=0;i<1000;i++)	
    {
		fprintf(ascendingbubble_txt,"%d\n","");
    }
    fclose(ascendingbubble_txt); 
	printf("�M������!\n");	
	/******************�ƭȼg�Jascending bubble.txt******************/  
	ascendingbubble_txt=fopen("ascending bubble.txt","wt");	
	printf("�g�Jascending bubble.txt��...\n");
    for(i=0;i<num;i++)	
    {
		fprintf(ascendingbubble_txt,"%d\n",*(data+i));
    }
    fclose(ascendingbubble_txt); 
	printf("�g�J����!\n");	    
	printf("\n");
	line();
	/******************����ʺA�t�m�O����******************/
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
