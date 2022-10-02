#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

#define MaxSize 600
typedef struct
{   char data[MaxSize];
    int length;
}  SqString;

SqString SubStr(SqString s,int i,int j)	//求子串.返回串s中从第i（1≤i≤n）个字符开始的、由连续j个字符组成的子串。
{
	SqString str;
	int k;
	str.length=0;
	if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
		return str;					//参数不正确时返回空串
	for (k=i-1;k<i+j-1;k++)  		//将s.data[i..i+j]复制到str
		str.data[k-i+1]=s.data[k];
	str.length=j;
	return str;
}
void GetNext(SqString t,int next[])		//由模式串t求出next值
{
	int j,k;
	j=0;k=-1;next[0]=-1;
	while (j<t.length-1)
	{
		if (k==-1 || t.data[j]==t.data[k]) 	//k为-1或比较的字符相等时
		{
			j++;k++;
			next[j]=k;
			//printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,k);
       	}
       	else
		{
			k=next[k];
			//printf("(2) k=%d\n",k);
		}
	}
}
int KMPIndex(SqString s,SqString t)  //KMP算法
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while (i<s.length && j<t.length)
	{
		if (j==-1 || s.data[i]==t.data[j])
		{
			i++;j++;  			//i,j各增1
		}
		else j=next[j]; 		//i不变,j后退
    }
    if (j>=t.length)
		return(i-t.length);  	//返回匹配模式串的首字符下标
    else
		return(-1);        		//返回不匹配标志
}

void Virus_detection()
{
   int num, flag=0;
   char temp[600];
   ifstream inFile("病毒感染检测输入数据.txt");
   ofstream outFile("病毒感染检测输出结果.txt");
   inFile>>num;//读取待检测的任务数
   while(num--) //依次检测每对病毒DNA和人的DNA是否匹配
   {
      SqString Virus,Person, VirusTmp;
      inFile>>Virus.data;//读取病毒DNA序列
      inFile>>Person.data;//读取人的DNA序列
      Person.length = strlen(Person.data);
      Virus.length = strlen(Virus.data);
      strcpy(VirusTmp.data, Virus.data); strcat(VirusTmp.data, Virus.data);VirusTmp.length = 2*Virus.length;


      for(int i=0;i<Virus.length;i++)
      {
        flag= KMPIndex(Person, SubStr(VirusTmp,i+1,Virus.length));	//模式匹配
        if(flag!=-1)break;
      }


      if(flag!=-1)
         outFile<<Virus.data<<"	"<<Person.data<<"	"<<"YES"<<endl;
      else
         outFile<<Virus.data<<"	"<<Person.data<<"	"<<"NO"<<endl;
   }
}

int main()
{
	Virus_detection();
	printf("检测完毕！\n");
	return 0;
}
