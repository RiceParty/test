#include<iostream>
#define Len 35
#define LenA 20
#define LenB 17
using namespace std;
void InitAd(int a[][Len])
{
	for(int i=0;i<Len;i++)
		for(int j=0;j<Len;j++)
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=1024;
}

void InitSubway(int a[][Len],int* b,const int len)
{
	for(int i=0;i<len;i++)
	{
		a[b[i]][b[i+1]]=1;
		a[b[i+1]][b[i]]=1;
	}
}

void Floyd(int a[][Len])
{
	for(int k=0;k<Len;k++)
		for(int i=0;i<Len;i++)
			for(int j=0;j<Len;j++)
				if(a[i][j]>a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[k][j];
}
int main()
{
	int ad[Len][Len];
	InitAd(ad);
	int subA[LenA]={0,1,2,3,4,5,6,7,8,33,9,10,11,12,34,13,14,15,16,17};
	int subB[LenB]={18,19,20,21,22,33,23,24,25,26,27,34,28,29,30,31,32};
	InitSubway(ad,subA,LenA);
	InitSubway(ad,subB,LenB);
	Floyd(ad);
	int start,end;
	while(1)
	{
		cout<<"enter starting station:"<<endl;
		cin>>start;
		cout<<"enter ending station:"<<endl;
		cin>>end;
		cout<<"shortest line:"<<ad[start][end]<<endl;
	}
	return 0;
}
