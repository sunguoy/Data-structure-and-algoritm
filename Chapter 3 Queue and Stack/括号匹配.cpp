#include <stdio.h>
#include <stdlib.h>
int com(char *s,char *c,char *p)
{
 int n=0;
 p=c;
 while(*p != '\0')
 {
  if(*p == '(' || *p == '[' || *p == '{')
    s[n++]=*p;    
  else if(*p == ')' || *p == ']' || *p == '}')
    {
     if(n == 0)    {return 0;}
     if(*p == ')' && s[n-1]== '('  ||  *p==']' && s[n-1]=='[' ||  *p=='}' && s[n-1]=='{')
        n--;
     else return 0;
    }                      
   p++;
 } 
return 1;                      
}                       
int main()
{
 char s[500],c[500],*p;
 scanf("%s",c);
 printf("%d\n",com(s,c,p));  
 system("pause");
 return 0;    
}
