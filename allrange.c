#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
void My_itoa(int value,char *str,int hex)
{
	int i=0;
	do
	{
		int num=value%hex;
		if(num<10)
			str[i++]=num+'0';
		else
			str[i++]=num+'A'-10;
	}
	while(value/=hex);
	str[i]='\0';
	char temp;
	for(int j=0;j<i/2;j++)
	{
		temp=str[j];
		str[j]=str[i-j-1];
		str[i-j-1]=temp;
	}
}

void Allrange(char *str,int size)
{
	if(size==1)
		cout<<str<<endl;
	else
	{
		for(int i=0;i<size;i++)
		{
			swap(str[i],str[size-1]);
			Allrange(str,size-1);
			swap(str[i],str[size-1]);
		}
	}
}
int main()
{
	char str[10];
	int value;
	cout<<"enter an integer:";
	cin>>value;
//	int hex;
//	cout<<"enter hex:";
//	cin>>hex;
	My_itoa(value,str,10);
	int i=strlen(str);
//	cout<<"translate int to char:"<<str<<endl;
	Allrange(str,i);
	return 0;
}
