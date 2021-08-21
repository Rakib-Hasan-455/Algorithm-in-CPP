#include <stdio.h>


void bubblesort(int arr[], int len){
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if(arr[j] > arr[j+1]){
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void Print(int arr[], int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 1, 4, 2, 5, 9, 7};
	int len = sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr, len);
	Print(arr, len);
	return 0;
}