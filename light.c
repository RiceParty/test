#include<iostream>
#include<math.h>
using namespace std;

int findfactor(int a)
{
//	cout<<"factor of ";
//	cout.width(5);
//	cout<<a;
//	cout<<":";
	int num=0;
	for(int i=1;i<=a;i++)
		if(a%i==0) 
		{
//			cout<<i<<" ";
			num++;
		}
//	cout<<endl;
	return num;
}
int main()
{
	unsigned short a;
	cout<<"enter num of light(-1 means end):"<<endl;
	while(cin>>a&&a!=-1)
	{
		int num=0;
		for(int i=1;i<=a;i++)
			if(findfactor(i)%2!=0)
				num++;
		cout<<num<<endl;

		num=0;
		for(int i=1;i*i<=a;i++)
			if(i*i<=a)
				num++;
		cout<<num<<endl;
	}
//	cout<<sizeof(a)<<endl;
//	cout<<pow(2,16)<<endl;
	return 0;
}
