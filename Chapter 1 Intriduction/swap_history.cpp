#include<stdio.h>
#include<iostream>
using namespace std;

//3、参数的引用传递方式
void swap(int &a, int &b)
{
	printf("swap������a�ĵ�ַΪ%p, b�ĵ�ַΪ%p \n", &a,&b);
	int temp = a;
	a = b;
	b = temp;
	printf("swap a = %d, b = %d",a,b);
}
int main()
{
	int a=111,b=222;
	printf("main������a�ĵ�ַΪ%p, b�ĵ�ַΪ%p \n", &a,&b);
	printf("Before swap a = %d, b = %d\n",a,b);
	swap(a,b);
	printf("After swap a = %d, b = %d \n",a,b);

}

/*
1、参数的传值调用方式
void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	printf("swap a = %d, b = %d",a,b);
}
int main()
{
	int a=111,b=222;
	printf("Before swap a = %d, b = %d\n",a,b);
	swap(a,b);
	printf("After swap a = %d, b = %d \n",a,b);

}
*/

/*
2、参数的指针调用方式
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap a = %d, b = %d",*a,*b);
}
int main()
{
	int a=111,b=222;
	printf("Before swap a = %d, b = %d\n",a,b);
	swap(&a,&b);
	printf("After swap a = %d, b = %d \n",a,b);

}
*/
