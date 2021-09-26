//单链表基本运算算法
#include <stdio.h>
#include <malloc.h>


typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;		//指向后继结点
} LinkNode;					//声明单链表结点类型


void CreateListF(LinkNode *&L,ElemType a[],int n)
//头插法建立单链表
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头结点
	L->next=NULL;
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点s
		s->data=a[i];
		s->next=L->next;			//将结点s插在原开始结点之前,头结点之后
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//尾插法建立单链表
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头结点
	L->next=NULL;
	r=L;					//r始终指向终端结点,开始时指向头结点
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点s
		s->data=a[i];
		r->next=s;			//将结点s插入结点r之后
		r=s;
	}
	r->next=NULL;			//终端结点next域置为NULL
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头结点
	L->next=NULL;
}
void DestroyList(LinkNode *&L)
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);	//此时p为NULL,pre指向尾结点,释放它
}
bool ListEmpty(LinkNode *L)
{
	return(L->next==NULL);
}
int ListLength(LinkNode *L)
{
	LinkNode *p=L;int i=0;
	while (p->next!=NULL)
	{	i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkNode *L)
{
	LinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkNode *L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L;
	if (i<=0) return false;		//i错误返回假
	while (j<i && p!=NULL)
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//不存在第i个数据结点
		return false;
	else						//存在第i个数据结点
	{	e=p->data;
		return true;
	}
}
int LocateElem(LinkNode *L,ElemType e)
{
	LinkNode *p=L->next;
	int n=1;
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		n++;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
bool ListInsert(LinkNode *&L,int i,ElemType e)
{
	int j=0;
	LinkNode *p=L,*s;
	if (i<=0) return false;			//i错误返回假
	while (j<i-1 && p!=NULL)		//查找第i-1个结点p
	{	j++;
		p=p->next;
	}
	if (p==NULL)					//未找到位序为i-1的结点
		return false;
	else							//找到位序为i-1的结点*p
	{	s=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点*s
		s->data=e;
		s->next=p->next;			//将s结点插入到结点p之后
		p->next=s;
		return true;
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L,*q;
	if (i<=0) return false;		//i错误返回假
	while (j<i-1 && p!=NULL)	//查找第i-1个结点
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//未找到位序为i-1的结点
		return false;
	else						//找到位序为i-1的结点p
	{	q=p->next;				//q指向要删除的结点
		if (q==NULL)
			return false;		//若不存在第i个结点,返回false
		e=q->data;
		p->next=q->next;		//从单链表中删除q结点
		free(q);				//释放q结点
		return true;
	}
}

//【例2.6】的算法:单链表L拆分成两个单链表
void split(LinkNode *&L,LinkNode *&L1,LinkNode *&L2)
{	LinkNode *p=L->next,*q,*r1;	//p指向第1个数据结点
	L1=L;					//L1利用原来L的头结点
	r1=L1;					//r1始终指向L1的尾结点
	L2=(LinkNode *)malloc(sizeof(LinkNode));	//创建L2的头结点
	L2->next=NULL;			//置L2的指针域为NULL
	while (p!=NULL)
	{	r1->next=p;			//采用尾插法将结点p(data值为ai)插入L1中
		r1=p;
		p=p->next;			//p移向下一个结点(data值为bi)
		q=p->next;			//由于头插法修改p的next域,故用q保存结点p的后继结点
		p->next=L2->next;	//采用头插法将结点p插入L2中
		L2->next=p;
		p=q;				//p重新指向ai+1的结点
	}
	r1->next=NULL;			//尾结点next置空
}

/*
int main()
{
	LinkNode *L,*L1,*L2;
	int n=10;
	ElemType a[]={1,2,3,4,5,6,7,8,9,10};
	InitList(L);
	InitList(L1);
	InitList(L2);
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("L->L1,L2\n");
	split(L,L1,L2);
	printf("L1:");DispList(L1);
	printf("L2:");DispList(L2);
	DestroyList(L1);
	DestroyList(L2);
	return 1;
}
*/
