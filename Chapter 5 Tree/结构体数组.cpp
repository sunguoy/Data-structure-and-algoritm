#include<stdio.h>

typedef struct node
{
    int num;
    char name[10];
}Stu[3];

int main()
{
    Stu stu ={{111111, "Jack"},{222222, "Mike"},{333333, "Lucy"}};
    for(int i=0;i<3;i++)
        printf("name = %s \n", stu[i].name);
    return 0;
}
