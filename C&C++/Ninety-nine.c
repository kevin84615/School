/*
  Name: hw4
  Copyright:鄭少齊 
  Author: 鄭少齊
  Date: 22/05/14 04:34
  Description: 九十九點 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
int card_order=0,drop_handcard=0,rank=0;
char sub;
struct card
{
	char face;
	int suit;
}d[52],player[4],AI[4],drop,temp;
void generate(struct card[]);
void shuffle(struct card[]);
void pt(struct card);
void deal_card(struct card[],struct card[]);
void player_drop_card();
void AI_run();
int main()
{	
    int i=0;
    /*-------------------------------------------------*///產生新牌 
	printf("產生新的一副牌中...\n");
	generate(d);
	printf("已產生一副新的牌!!!\n\n");
	/*-------------------------------------------------*///顯示新牌 
	printf("顯示新的一副牌\n");		
	for(i=0;i<52;i++)
	{
		pt(d[i]);
		printf(" ");
		if(i%13==12)
		    printf("\n");
    }
	/*-------------------------------------------------*///洗牌 
	printf("\n洗牌中...\n");
	shuffle(d);
	printf("洗牌完成!!!\n\n");
	/*-------------------------------------------------*///顯示洗牌後的牌組 
	printf("顯示洗牌後的牌組\n");	
	for(i=0;i<52;i++)
	{
		pt(d[i]);
		printf(" ");
		if(i%13==12)
		    printf("\n");
	}
	printf("按下任意鍵開始遊戲");
    getch();
    /*-------------------------------------------------*///開局發牌 
	printf("\n\n");	

    do
    {
    	deal_card(player,AI);
    	player_drop_card();
    	if(rank>99)
		{
			printf("you lose!!\n\n");
			break;
    	}
    	deal_card(player,AI);
    	AI_run();
    	if(rank>99)
		{
			printf("computer lose!!\n\n");
			break;
    	}
    }while(1);

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
void player_drop_card()
{
	int i=0;
	printf("(玩家)");
	for(i=0;i<4;i++)
	{
		pt(player[i]);
		printf(" ");
	}

	
	do
	{		
		printf("丟牌(1~4) : ");	
		scanf("%d",&drop_handcard);	
	}while(drop_handcard<1||drop_handcard>4);
    
	drop.face=player[drop_handcard-1].face;
	drop.suit=player[drop_handcard-1].suit;
	player[drop_handcard-1].face=NULL;
	
	if(drop.suit>=0&&drop.suit<=8)
	{
		rank=rank+drop.suit+1;
	}
	else if(drop.suit==9)
	{
		printf("輸入 + 或 - : ");
		fflush(stdin);
		sub=getchar();
		if(sub=='+')
		    rank+=10;
		if(sub=='-')
		    rank-=10;
	}
	else if(drop.suit==10)
	{
		printf("PASS!!\n");
	}
	else if(drop.suit==11)
	{
		printf("輸入 + 或 - : ");
		fflush(stdin);
		sub=getchar();
		if(sub=='+')
		    rank+=20;
		if(sub=='-')
		    rank-=20;
	}
	else if(drop.suit==12)
	{
		rank=99;
	}
	printf("\n總分為:%d\n\n",rank);
	printf("\n");
}
void AI_run()
{
	int i;
	printf("(電腦)");
	i=rand()%4;
	drop.face=AI[i].face;
	drop.suit=AI[i].suit;


	if(drop.suit>=0&&drop.suit<=8)
	{
		printf("丟牌:");
	    pt(drop);
		rank=rank+drop.suit+1;
	}
	else if(drop.suit==9)
	{
		printf("丟牌:");
	    pt(drop);
		rank+=10;
	}
	else if(drop.suit==10)
	{
		printf("丟牌:");
	    pt(drop);
		printf("PASS!!\n");
	}
	else if(drop.suit==11)
	{
		printf("丟牌:");
	    pt(drop);
		rank+=20;
	}
	else if(drop.suit==12)
	{
		printf("丟牌:");
	    pt(drop);
		rank=99;
	}
	AI[i].face='\0';	
	AI[i].suit=0;
	printf("\n\n總分為:%d\n\n",rank);
}
