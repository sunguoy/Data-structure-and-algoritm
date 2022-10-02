#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

#define MaxSize 600
typedef struct
{   char data[MaxSize];
    int length;
}  SqString;

SqString SubStr(SqString s,int i,int j)	//���Ӵ�.���ش�s�дӵ�i��1��i��n�����ַ���ʼ�ġ�������j���ַ���ɵ��Ӵ���
{
	SqString str;
	int k;
	str.length=0;
	if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
		return str;					//��������ȷʱ���ؿմ�
	for (k=i-1;k<i+j-1;k++)  		//��s.data[i..i+j]���Ƶ�str
		str.data[k-i+1]=s.data[k];
	str.length=j;
	return str;
}
void GetNext(SqString t,int next[])		//��ģʽ��t���nextֵ
{
	int j,k;
	j=0;k=-1;next[0]=-1;
	while (j<t.length-1)
	{
		if (k==-1 || t.data[j]==t.data[k]) 	//kΪ-1��Ƚϵ��ַ����ʱ
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
int KMPIndex(SqString s,SqString t)  //KMP�㷨
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while (i<s.length && j<t.length)
	{
		if (j==-1 || s.data[i]==t.data[j])
		{
			i++;j++;  			//i,j����1
		}
		else j=next[j]; 		//i����,j����
    }
    if (j>=t.length)
		return(i-t.length);  	//����ƥ��ģʽ�������ַ��±�
    else
		return(-1);        		//���ز�ƥ���־
}

void Virus_detection()
{
   int num, flag=0;
   char temp[600];
   ifstream inFile("������Ⱦ�����������.txt");
   ofstream outFile("������Ⱦ���������.txt");
   inFile>>num;//��ȡ������������
   while(num--) //���μ��ÿ�Բ���DNA���˵�DNA�Ƿ�ƥ��
   {
      SqString Virus,Person, VirusTmp;
      inFile>>Virus.data;//��ȡ����DNA����
      inFile>>Person.data;//��ȡ�˵�DNA����
      Person.length = strlen(Person.data);
      Virus.length = strlen(Virus.data);
      strcpy(VirusTmp.data, Virus.data); strcat(VirusTmp.data, Virus.data);VirusTmp.length = 2*Virus.length;


      for(int i=0;i<Virus.length;i++)
      {
        flag= KMPIndex(Person, SubStr(VirusTmp,i+1,Virus.length));	//ģʽƥ��
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
	printf("�����ϣ�\n");
	return 0;
}
