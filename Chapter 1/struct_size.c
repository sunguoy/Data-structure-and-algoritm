#include<stdio.h>

struct E1
{ int a;char b; char c};

struct E2
{ char b; char c};

struct E3
{ int a;char b; };

struct E4
{ char b; int a;};
int main()
{
    struct E1 e1;
    struct E2 e2;
    struct E3 e3;
    struct E4 e4;

    printf("e1��ռ�ڴ��СΪ��%d \n", sizeof(e1));
    printf("e2��ռ�ڴ��СΪ��%d \n", sizeof(e2));
    printf("e3��ռ�ڴ��СΪ��%d \n", sizeof(e3));
    printf("e4��ռ�ڴ��СΪ��%d \n", sizeof(e4));

    return 0;
}

