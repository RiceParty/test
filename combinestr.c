#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
int main()
{
	char s1[10],s2[10];
	cout<<"enter string one:";
	cin>>s1;
	cout<<"enter string two:";
	cin>>s2;
	char *p=s1,*q=s2,*result,*s;
	result=(char*)malloc(strlen(s1)+strlen(s2)+1);
	s=result;
	while(*p)
	{
		*s++=*p++;
	}
	while(*q)
	{
		*s++=*q++;
	}
	*++s='\0';
	cout<<result<<endl;
	return 0;
}
