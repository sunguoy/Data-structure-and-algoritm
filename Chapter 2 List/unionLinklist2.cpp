//����2.14�����㷨����·�鲢:���õ�����ʵ��
#include "linklist.cpp"
void UnionList2(LinkNode *LA,LinkNode *LB,LinkNode *&LC)
{
	LinkNode *pa=LA->next,*pb=LB->next,*pc;
	LC = LA;		//����LC��ͷ���
	pc = LC;							//pcʼ��ָ��LC�����һ�����
	while (pa!=NULL && pb!=NULL)
	{
		if (pa->data<pb->data)
		{
			pc->next=pa;
			pc=pa;		//����β�巨�����s���뵽LC�����
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;		//����β�巨�����s���뵽LC�����
			pb=pb->next;
		}
	}
	if (pa!=NULL)
        pc->next = pa;
	if(pb!=NULL)
        pc->next  = pb;
}
int main()
{
	LinkNode *L1,*L2,*L3;
	ElemType a[]={1,3,5};
	ElemType b[]={2,4,8,10};
	CreateListR(L1,a,3);
	printf("L1:");DispList(L1);
	CreateListR(L2,b,4);
	printf("L2:");DispList(L2);
	printf("�鲢\n");
	UnionList2(L1,L2,L3);
	printf("L3:");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 1;
}

