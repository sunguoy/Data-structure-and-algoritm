#include<stdio.h>

#define MaxSize 100

typedef struct{
    int no;
    char name[20];
    char sex;//M表示男，F表示女
}student;

typedef struct{
    int ISBN;
    char name[20];
}Book;
typedef struct
{  Book data[MaxSize];
   int length;
} SqList;    	//顺序表类型


int main()
{
    student stut1 = {338,"Lily",'F'};
    student *stut2 = &stut1;
    student stu[5]={
                            {110,"Mike",'M'},
                            {220,"Mary",'F'},
                            {330,"Jack",'M'},
                            {331,"Linda",'F'},
                            {337,"Lucy",'F'}
                            };//stu[0], stu[1], stu[2], stu[3], stu[4]
    printf("%c \n", stut1.sex);
    stut2->sex = 'M';
    printf("%c \n", stut1.sex);
    printf("%c \n", stut2->sex);

    SqList * L=(SqList *)malloc(sizeof(SqList));
    printf("The size of Book is %d \n",sizeof(Book));
    printf("The size of L is %d \n",sizeof(L));
    printf("The size of SqList %d \n",sizeof(SqList));


    return 0;
}
