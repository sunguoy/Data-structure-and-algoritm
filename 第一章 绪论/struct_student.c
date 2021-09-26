#include<stdio.h>

struct student{
    int no;
    char name[20];
    char sex;//M表示男，F表示女
    struct student* next;

    void print(int no)
    {

    }

};

int main()
{
    struct student stu[5]={
                            {110,"Mike",'M'},
                            {220,"Mary",'F'},
                            {330,"Jack",'M'},
                            {331,"Linda",'F'},
                            {337,"Lucy",'F'}
                            };//stu[0], stu[1], stu[2], stu[3], stu[4]
    printf("%u %u %u %u %u\n",&stu[0],&stu[1],&stu[2],&stu[3], &stu[4]);
    printf("%d \n", sizeof(stu[0]));

    return 0;
}
