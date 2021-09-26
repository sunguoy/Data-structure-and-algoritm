//【例2.14】的算法，二路归并:采用单链表实现
#include "linklist.cpp"
void UnionList2(LinkNode *LA,LinkNode *LB,LinkNode *&LC)
{
	LinkNode *pa=LA->next,*pb=LB->next,*pc;
	LC = LA;		//创建LC的头结点
	pc = LC;							//pc始终指向LC的最后一个结点
	while (pa!=NULL && pb!=NULL)
	{
		if (pa->data<pb->data)
		{
			pc->next=pa;
			pc=pa;		//采用尾插法将结点s插入到LC的最后
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;		//采用尾插法将结点s插入到LC的最后
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
	printf("归并\n");
	UnionList2(L1,L2,L3);
	printf("L3:");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 1;
}

