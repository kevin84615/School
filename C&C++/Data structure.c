#include <stdio.h>
#include <stdlib.h>
#define NODE struct stype
NODE
{int data;
 NODE *next;
};
NODE *printList (NODE *h)
{
    NODE *p=h;
    while (p!=NULL)
    {printf("%3d,",p->data);
     p=p->next;
    }
}
NODE *addList(NODE *h,int item,int index)
{
    int i=0;NODE *p=h;
    NODE *q=(NODE *)calloc(1,sizeof(NODE));
    q->data=item;q->next=NULL;
    if (h==NULL) return q;//空串列的處置 
    if (index==0)
    {q->next=p;
     h=q;
     }
    else if (index>0)
    {
     while((++i <index)&&(p->next!=NULL))
      {p=p->next;
      }//尋找下一個節點 
       q->next=p->next;
       p->next=q;
    }
    return h;
}
NODE *delList(NODE *h,int index)
{
    int i=0;
    NODE *p=h;
    if (h==NULL) return h;
    if (index==0)
    {h=p->next;
    }
    else if (index >0 )
    {
     while((++i <index)&&(p->next!=NULL))
      {p=p->next;
      }
       if (p->next!=NULL)
        {p->next=p->next->next;
        }
    }
    return h;
}
NODE *newList(int A[],int size)
{
    int i =0;
    NODE *h,*p,*q;
    h=p=q=NULL;
    for (i=0;i<size;i++)
    {q=(NODE *)calloc(1,sizeof(NODE));
     q->data =A[i];
     q->next = NULL;
        if (i==0)
        {h=p=q;
        }
        else
        {p->next=q;//設定一個指標p永遠指向最後一個元素 
         p=q;
        }
    }
    return h;
}
NODE *revList(NODE *h)
{
    NODE *p,*q;
    p=h;
    q=(NODE *)calloc(1,sizeof(NODE));
    q->data=p->data;
    q->next=NULL;
    do{p=p->next;
       q=addList(q,p->data,0);
    }while(p->next!=NULL);
    h=q;
}
void main(void)
{
    int theArray[]={5,10,15,20,25};
    NODE *theList = newList(theArray,5);
    theList = addList (theList,1,-1);
    theList = addList (theList,30,10);
    theList = addList (theList,12,3);
    theList = delList (theList,0);
    theList = delList (theList,10);
    theList = delList (theList,-3);
    printf("原始串列為：\n"); 
    printList(theList);
    printf("\n轉換後：\n");
    theList=revList(theList);
    printList(theList);
    system("PAUSE");
}

