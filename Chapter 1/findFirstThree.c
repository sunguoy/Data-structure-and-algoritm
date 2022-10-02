#include<stdio.h>
#define MAXLEN 500

char findFirstThree(char str[])
{
    int count[200];
    for(int j=0;j<200;j++)
        count[j]=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]>='a')&&(str[i]<='z') || (str[i]>='A')&&(str[i]<='Z'))
        {
            count[str[i]] = count[str[i]]+1;
            if(count[str[i]]==3)
                return str[i];
        }
    }
}

int main()
{
    char str[MAXLEN], res;
    //scanf("%s",str);
    gets(str);
    res = findFirstThree(str);
    printf("%c \n",res);

}
