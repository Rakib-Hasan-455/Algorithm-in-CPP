#include<stdio.h>

int main(int argc, char const *argv[])
{
	int arr[] = {10, 20, 30, 40};
	printf("%d\n",sizeof(arr));
	int len = sizeof(arr) / sizeof(arr[0]); 
	int x;
	scanf("%d",&x);
	for (int i = 0; i < len; ++i)  //O[n]
	{
		if (arr[i] == x)		 //O[1]
		{
			printf("Found\n");
		}
	}
	return 0; 
}