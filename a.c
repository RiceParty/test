#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class A
{
	A();
	~A();
	int a;
};
class B:public A
{};

void fun(int a)
{
	static int b=0;
	if(a>5) 
	{
		a--;
		b++;
		fun(a);
	}
	else
		cout<<b<<endl;
}
int main()
{	
//	cout<<sizeof(A)<<endl<<sizeof(B)<<endl;
//	char a[]="aa";
//	bool flag=true;
//	cout<<sizeof(a)<<endl<<strlen(a)<<endl;
//	cout<<flag<<endl;
//	flag=!flag;
//	cout<<flag<<endl;
//	int a[10];
//	int b[10]={0};
//	for(int i=0;i<10;i++)
//		cout<<a[i]<<" ";
//	for(int j=0;j<10;j++)
//		cout<<b[j]<<" ";
	unsigned	short a=-1,b=-32768;
	printf("%d,%x\n",a,b);
	return 0;
}

