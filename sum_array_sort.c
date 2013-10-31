#include<iostream>
using namespace std;

bool find(int array[],int lenth,int sum,int& num1,int& num2)
{
	if(lenth<1) return false;

	int head=0,tail=lenth-1;
	while(head<tail)
	{
		if(sum==(array[head]+array[tail]))
		{
			num1=array[head];
			num2=array[tail];
			return true;
		}
		else if(sum>(array[head]+array[tail]))
			head++;
		else 
			tail--;
	}
	return false;
}
int main()
{
	int array[5];
	int num1,num2;
	int sum;
	cout<<"enter array element:"<<endl;
	for(int i=0;i<5;i++)
		cin>>array[i];
	cout<<"enter sum:"<<endl;
	cin>>sum;
	if(find(array,5,sum,num1,num2))
		cout<<num1<<" "<<num2<<" "<<endl;
	else
		cout<<"no match"<<endl;
	return 0;
}
