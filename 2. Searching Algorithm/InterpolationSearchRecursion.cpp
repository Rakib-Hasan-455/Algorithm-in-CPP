#include <iostream>
using namespace std;

int i = 1;

int Search(int arr[], int search, int left, int right){
	if(search > arr[right] || search < arr[left]){
		return -1;
	}
	if(left <= right){
		int middle = left + (((double)(right - left) /
            (arr[right] - arr[left])) * (search - arr[left]));
		cout << "Step "<< i++ << " Left: " << left << " Right: " << right << " Array left: " << arr[left] << " Array right " << arr[right] << " middle: " << middle << endl;

		if(arr[middle] == search){
			return middle;
		} else if(arr[middle] < search){
			return Search(arr, search, middle + 1, right); //T(n/2)
		} else if(arr[middle] > search){
			return Search(arr, search, left, middle - 1); //T(n/2)
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[] = { 2, 5, 7, 9, 11, 20, 30, 50, 80};
	int right = sizeof(arr)/sizeof(arr[0]);
	int search;
	scanf("%d", &search);
	int result = Search(arr, search, 0, right-1);
	if(result == -1){
		printf("Not Found!\n");
	} else {
		printf("Found at index %d!\n", result);
	}
	return 0;
}

