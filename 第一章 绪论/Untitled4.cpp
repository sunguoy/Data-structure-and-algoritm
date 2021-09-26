//���룺������x, y
//�����������x��y��ֵ
#include<stdio.h>

void swap_val(int a, int b) //��ֵ����
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void swap_pointer(int *a, int *b)//��ָ��ĵ���
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int &a, int &b)//���õ���
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
