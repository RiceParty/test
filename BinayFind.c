#include<iostream>
#define N 11
using namespace std;
int BinaryFind(int arr[N],int n)
{
	int left=0,right=N-1,mid=0;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(n==arr[mid])
			return mid;
		else	if(n<arr[mid])
			right=mid-1;
		else
			left=mid+1;
	}
	return -1;
}

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<N;i++)
		cout<<BinaryFind(a,i)<<" ";
	cout<<endl;
	return 0;
}
