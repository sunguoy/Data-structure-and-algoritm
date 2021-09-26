#include "sqlist.cpp"


/*
    ****3、顺序表其他高级操作****
*/
void delnode1(SqList *&L, ElemType x) //删除顺序表中所有值为x的元素
{  int k=0, i;		//k记录值不等于x的元素个数
   for (i=0;i<L->length;i++)
      if (L->data[i]!=x)    	//若当前元素不为x，将其插入A中
      {   L->data[k]=L->data[i];
          k++;		 	//不等于x的元素增1
      }
   L->length=k;		//顺序表L的长度等于k
}



int main()
{
    SqList *L;
    int a[]={72,70,65,66,77,11,22,33,44,55,66,66,66};


    CreateList(L,a,13);
    printf("原顺序表为：\n");
    DispList(L);

    printf("\n \n删除后的顺序表为：\n");
    delnode1(L, 66);
    DispList(L);
}
