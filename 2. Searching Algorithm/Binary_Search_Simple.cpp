#include <stdio.h>
int Search(int arr[], int search, int left, int right){
	while(left <= right){
		int middle = left + (right - left) / 2;

		if(arr[middle] == search){
			return middle;
		} else if(arr[middle] < search){
			left = middle + 1;
		} else if(arr[middle] > search){
			right = middle - 1;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[] = { 2, 5, 7, 9, 11};
	int len = sizeof(arr)/sizeof(arr[0]);
	int search;
	scanf("%d", &search);
	int result = Search(arr, search, 0, len-1);
	if(result == -1){
		printf("Not Found!\n");
	} else {
		printf("Found at index %d!\n", result);
	}
	return 0;
}

