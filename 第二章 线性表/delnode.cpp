#include "sqlist.cpp"


/*
    ****3��˳��������߼�����****
*/
void delnode1(SqList *&L, ElemType x) //ɾ��˳���������ֵΪx��Ԫ��
{  int k=0, i;		//k��¼ֵ������x��Ԫ�ظ���
   for (i=0;i<L->length;i++)
      if (L->data[i]!=x)    	//����ǰԪ�ز�Ϊx���������A��
      {   L->data[k]=L->data[i];
          k++;		 	//������x��Ԫ����1
      }
   L->length=k;		//˳���L�ĳ��ȵ���k
}



int main()
{
    SqList *L;
    int a[]={72,70,65,66,77,11,22,33,44,55,66,66,66};


    CreateList(L,a,13);
    printf("ԭ˳���Ϊ��\n");
    DispList(L);

    printf("\n \nɾ�����˳���Ϊ��\n");
    delnode1(L, 66);
    DispList(L);
}
