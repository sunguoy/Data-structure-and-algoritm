//��������������㷨
#include <stdio.h>
#include <malloc.h>


typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;		//ָ���̽��
} LinkNode;					//����������������


void CreateListF(LinkNode *&L,ElemType a[],int n)
//ͷ�巨����������
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//β�巨����������
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		r->next=s;			//�����s������r֮��
		r=s;
	}
	r->next=NULL;			//�ն˽��next����ΪNULL
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
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
	free(pre);	//��ʱpΪNULL,preָ��β���,�ͷ���
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
	if (i<=0) return false;		//i���󷵻ؼ�
	while (j<i && p!=NULL)
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//�����ڵ�i�����ݽ��
		return false;
	else						//���ڵ�i�����ݽ��
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
	if (i<=0) return false;			//i���󷵻ؼ�
	while (j<i-1 && p!=NULL)		//���ҵ�i-1�����p
	{	j++;
		p=p->next;
	}
	if (p==NULL)					//δ�ҵ�λ��Ϊi-1�Ľ��
		return false;
	else							//�ҵ�λ��Ϊi-1�Ľ��*p
	{	s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��*s
		s->data=e;
		s->next=p->next;			//��s�����뵽���p֮��
		p->next=s;
		return true;
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L,*q;
	if (i<=0) return false;		//i���󷵻ؼ�
	while (j<i-1 && p!=NULL)	//���ҵ�i-1�����
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ�λ��Ϊi-1�Ľ��
		return false;
	else						//�ҵ�λ��Ϊi-1�Ľ��p
	{	q=p->next;				//qָ��Ҫɾ���Ľ��
		if (q==NULL)
			return false;		//�������ڵ�i�����,����false
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��q���
		free(q);				//�ͷ�q���
		return true;
	}
}

//����2.6�����㷨:������L��ֳ�����������
void split(LinkNode *&L,LinkNode *&L1,LinkNode *&L2)
{	LinkNode *p=L->next,*q,*r1;	//pָ���1�����ݽ��
	L1=L;					//L1����ԭ��L��ͷ���
	r1=L1;					//r1ʼ��ָ��L1��β���
	L2=(LinkNode *)malloc(sizeof(LinkNode));	//����L2��ͷ���
	L2->next=NULL;			//��L2��ָ����ΪNULL
	while (p!=NULL)
	{	r1->next=p;			//����β�巨�����p(dataֵΪai)����L1��
		r1=p;
		p=p->next;			//p������һ�����(dataֵΪbi)
		q=p->next;			//����ͷ�巨�޸�p��next��,����q������p�ĺ�̽��
		p->next=L2->next;	//����ͷ�巨�����p����L2��
		L2->next=p;
		p=q;				//p����ָ��ai+1�Ľ��
	}
	r1->next=NULL;			//β���next�ÿ�
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
