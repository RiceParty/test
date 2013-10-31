#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int at;
int max;
int main()
{
	int mid;
	int mouse_count;
	printf("enter mouse count:");
	scanf("%d",&mouse_count);
	max=(int)pow(2,mouse_count);
	for(mid=1;mid<=mouse_count;mid++)
	{
		printf("mouse No.%d drink ",mid);
		for(at=1;at<max;at++)
		{
			if(at&(0x1<<(mid-1)))
				printf("%d\t",at);
		}
		putchar('\n');
	}
	return 0;
}
