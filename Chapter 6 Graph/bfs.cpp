//������ȱ����㷨
#include "graph.cpp"
#define MaxSize 100


//ͼ�Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
#include "graph.h"
//------------------------------------------------------------
//----�ڽӾ���Ļ��������㷨----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӾ���
{
	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
}
void DispMat(MatGraph g)	//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=INF)
				printf("%4d",g.edges[i][j]);
			else
				printf("%4s","��");
		printf("\n");
	}
}
//------------------------------------------------------------

//------------------------------------------------------------
//----�ڽӱ�Ļ��������㷨------------------------------------
//------------------------------------------------------------
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӱ�
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)								//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)								//����ڽӾ�����ÿ��Ԫ��
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)			//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ�����p
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	//����ͷ�巨������p
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=n;
}
void DispAdj(AdjGraph *G)	//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d[%d]��",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("��\n");
	}
}
void DestroyAdj(AdjGraph *&G)		//����ͼ���ڽӱ�
{	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)			//ɨ�����еĵ�����
	{	pre=G->adjlist[i].firstarc;	//pָ���i����������׽��
		if (pre!=NULL)
		{	p=pre->nextarc;
			while (p!=NULL)			//�ͷŵ�i������������б߽��
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//�ͷ�ͷ�������
}
//------------------------------------------------------------


//---------------------------------------------------------
//--������ȱ�����ʹ�ö��еĻ��������㷨-------------------
//---------------------------------------------------------
typedef int ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//---------------------------------------------------------

void BFS(AdjGraph *G,int v)  
{
	int w,i;
	ArcNode *p;
	SqQueue *qu;							//���廷�ζ���ָ��
	InitQueue(qu);							//��ʼ������
	int visited[MAXV];            			//���嶥����ʱ�־����
	for (i=0;i<G->n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%2d",v); 						//��������ʶ���ı��
	visited[v]=1;              				//���ѷ��ʱ��
	enQueue(qu,v);
	while (!QueueEmpty(qu))       			//�Ӳ���ѭ��
	{	
		deQueue(qu,w);						//����һ������w
		p=G->adjlist[w].firstarc; 			//ָ��w�ĵ�һ���ڽӵ�
		while (p!=NULL)						//����w�������ڽӵ�
		{	
			if (visited[p->adjvex]==0) 		//����ǰ�ڽӵ�δ������
			{
				printf("%2d",p->adjvex);  	//���ʸ��ڽӵ�
				visited[p->adjvex]=1;		//���ѷ��ʱ��
				enQueue(qu,p->adjvex);		//�ö������
           	}
           	p=p->nextarc;              		//����һ���ڽӵ�
		}
	}
	printf("\n");
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateAdj(G,A,n,e);			//�������̡̳���ͼ8.1(a)���ڽӱ�
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);					//����ڽӱ�G
	printf("�����������:");BFS(G,2);printf("\n");
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
