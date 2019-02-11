/*
  Name: hw3
  Copyright:�G�ֻ� 
  Author: �G�ֻ�
  Date: 08/05/14 23:22
  Description: �~�P�o�P 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int card_order=0;
struct card
{
	char face;
	int suit;
}
d[52],player[4],AI[4],temp;
void generate(struct card[]);
void shuffle(struct card[]);
void pt(struct card);
void deal_card(struct card[],struct card[]);
int main()
{	
    int i=0;
    /*-------------------------------------------------*///���ͷs�P 
	printf("���ͷs���@�ƵP��...\n");
	generate(d);
	printf("�w���ͤ@�Ʒs���P!!!\n\n");
	/*-------------------------------------------------*///��ܷs�P 
	printf("��ܷs���@�ƵP\n");		
	for(i=0;i<52;i++)
	{
		pt(d[i]);
		printf(" ");
		if(i%13==12)
		    printf("\n");
    }
	/*-------------------------------------------------*///�~�P 
	printf("\n�~�P��...\n");
	shuffle(d);
	printf("�~�P����!!!\n\n");
	/*-------------------------------------------------*///��ܬ~�P�᪺�P�� 
	printf("��ܬ~�P�᪺�P��\n");	
	for(i=0;i<52;i++)
	{
		pt(d[i]);
		printf(" ");
		if(i%13==12)
		    printf("\n");
	}
	/*-------------------------------------------------*///�o�P 
	deal_card(player,AI);
	printf("\n�H�U���q�����P\n");	
	for(i=0;i<4;i++)
	{
		pt(AI[i]);
		printf(" ");
	}
	printf("\n");
	printf("�H�U�����a���P\n");
	for(i=0;i<4;i++)
	{
		pt(player[i]);
		printf(" ");
	}
	printf("\n\n");
	system("PAUSE");	
	return 0;
}
void generate(struct card p[])
{
    int i=0;
    for(i=0;i<52;i++)
    {
    	if(i>=0&&i<=12)
    	{
    		p[i].face=6;
    		p[i].suit=i%13;
    	}
    	if(i>=13&&i<=25)
    	{
    		p[i].face=3;
    		p[i].suit=i%13;
    	}
    	if(i>=26&&i<=38)
    	{
    		p[i].face=4;
    		p[i].suit=i%13;
    	}
    	if(i>=39&&i<=51)
    	{
    		p[i].face=5;
    		p[i].suit=i%13;
    	}    	
    }	
}
void shuffle(struct card p[])
{
	int i,k,o;
	srand(clock()*999);
	for(o=0;o<100;o++)	
	{
		i=rand()%52;	    
	    k=rand()%52;
	    temp.suit=p[i].suit;
	    temp.face=p[i].face;
	    p[i].suit=p[k].suit;
	    p[i].face=p[k].face;
	    p[k].suit=temp.suit;
	    p[k].face=temp.face;
	}	
}
void pt(struct card d)
{
	if(d.suit==10)
	    printf("%cJ ",d.face);
	else if(d.suit==9)
	    printf("%c10",d.face);
	else if(d.suit==11)
	    printf("%cQ ",d.face);
	else if(d.suit==12)
	    printf("%cK ",d.face);
	else if(d.suit==0)
	    printf("%cA ",d.face);	    
	else    
	    printf("%c%d ",d.face,d.suit+1);	
}
void deal_card(struct card p[],struct card a[])
{
	int i;
	for(i=0;i<4;i++)
	{		
		if(strcmp(&p[i].face,"")==0)
		{
			p[i].face=d[card_order].face;
			p[i].suit=d[card_order].suit;		
			card_order++;		
		}
		if(strcmp(&a[i].face,"")==0)
		{
			a[i].face=d[card_order].face;
			a[i].suit=d[card_order].suit;
			card_order++;		
		}		
	}	
}
