#include<iostream>
using namespace std;
//²Î¿¼  https://blog.csdn.net/bumingchun/article/details/61616613


#define MAXSIZE 100
typedef int TElemType;
typedef TElemType SqBiTree[MAXSIZE];
SqBiTree bt;

int main()
{
    SqBiTree bt;
    for(int i=0;i<MAXSIZE; i++)bt[i]=i+1;
    for(int j=0;j<MAXSIZE;j++)cout<<bt[j]<<"  ";
    return 0;
}
