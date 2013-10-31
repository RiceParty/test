#include<iostream>
#include<algorithm>
using namespace std;
void Print(int array[],int n,int i)
{
	cout<<i<<":";
	for(int j=0;j<n;j++)
		cout<<array[j]<<" ";
	cout<<endl;
}

void InsertSort(int array[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(array[i]<array[i-1])
		{
			int j=i-1;
			int x=array[i];
			while(x<array[j]&&j>=0)
			{
				array[j+1]=array[j];
				j--;
			}
			array[j+1]=x;
		}
		Print(array,n,i);
	}
}

void SelectSort(int array[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int key=i;
		for(int j=i+1;j<n;j++)
		{
			if(array[key]>array[j])
					key=j;
		}
		int tmp;
		tmp=array[i];
		array[i]=array[key];
		array[key]=tmp;
		Print(array,n,i+1);
	}
}

void BubbleSort(int array[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
			if(array[j]>array[j+1])
			{
				int tmp;
				tmp=array[j];
				array[j]=array[j+1];
				array[j+1]=tmp;
			}
		Print(array,n,i+1);
	}
}

int Part(int array[],int low,int high)
{
	int key=array[low];
	while(low<high)
	{
		while(low<high&&array[high]>key)
			--high;
		swap(array[low],array[high]);
		while(low<high&&array[low]<key)
			++low;
		swap(array[low],array[high]);
	}
	Print(array,6,0);
	return low;
}

void QuickSort(int array[],int low,int high)
{
	if(low<high)
	{
		int key=Part(array,low,high);
		QuickSort(array,low,key-1);
		QuickSort(array,key+1,high);
	}
}

void Merge(int* initList,int* mergeList,const int l,const int m,const int n)
{
	int i1,iResult,i2;
	for(i1=l,iResult=l,i2=m+1;i1<=m&&i2<=n;iResult++)
		if(initList[i1]<=initList[i2])
		{
			mergeList[iResult]=initList[i1];
			i1++;
		}
		else
		{
			mergeList[iResult]=initList[i2];
			i2++;
		}
	copy(initList+i1,initList+m+1,mergeList+iResult);
	copy(initList+i2,initList+n+1,mergeList+iResult);
}

void MergePass(int* initList,int* resultList,const int n,const int s)
{
	int i;
	for(i=1;i<=n-2*s+1;i+=2*s)
			Merge(initList,resultList,i,i+s-1,n);
	if((i+s-1)<n)
		Merge(initList,resultList,i,i+s-1,n);
	else
		copy(initList+i,initList+n+1,resultList+i);
}

void MergeSort(int* a,const int n)
{
	int* tempList=new int[n+1];
	for(int l=1;l<n;l*=2)
	{
		MergePass(a,tempList,n,l);
		l*=2;
		MergePass(tempList,a,n,l);
	}
	delete[] tempList;
}
int main()
{
	int array[]={8,2,4,1,5,6};

	cout<<"array before sort:"<<endl;
	for(int i=0;i<6;i++)
		cout<<array[i]<<" ";
	cout<<endl;

	cout<<"Insert sort:"<<endl;
	InsertSort(array,6);

	int array1[]={8,2,4,1,5,6};
	cout<<"Select sort:"<<endl;
	SelectSort(array1,6);

	int array2[]={8,2,4,1,5,6};
	cout<<"Bubble sort:"<<endl;
	BubbleSort(array2,6);

	int array3[]={8,2,4,1,5,6};
	cout<<"Qucik sort:"<<endl;
	QuickSort(array3,0,5);

	int array4[]={8,2,4,1,5,6};
	cout<<"Merge sort:"<<endl;
	MergeSort(array4,6);
	Print(array4,6,0);
	return 0;
}
