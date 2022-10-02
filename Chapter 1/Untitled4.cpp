//输入：两个数x, y
//输出：交换后x和y的值
#include<stdio.h>

void swap_val(int a, int b) //传值调用
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void swap_pointer(int *a, int *b)//传指针的调用
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int &a, int &b)//引用调用
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x=1, y=2;
    printf("x=%d, y=%d \n", x, y);
    swap_ref(x, y);
    printf("x=%d, y=%d \n", x, y);
    return 0;
}
