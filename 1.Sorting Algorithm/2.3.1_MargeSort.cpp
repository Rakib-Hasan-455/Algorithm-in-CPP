#include<bits/stdc++.h> 
using namespace std; 

void mergeAccend(int arr[], int lo, int mid, int hi){
	int temp[100], k = 0, i = lo, j = mid+1;
	while(i <= mid && j <= hi){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid){
	temp[k++] = arr[i++];	
	}
	while(j <= hi){
	temp[k++] = arr[j++];	
	}
	for(i = lo, k = 0; i <= hi; i++, k++){
		arr[i] = temp[k];
	}	
}


void mergeSortAccend(int arr[], int lo, int hi){	
	if(lo == hi){
		return;
	}
	int mid = (lo + hi)/2;
	mergeSortAccend(arr, lo, mid);
	mergeSortAccend(arr, mid+1, hi);
	mergeAccend(arr, lo, mid, hi);	
}

int main(){

  int arr[100], n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
  	cin >> arr[i];
  }
	mergeSortAccend(arr, 0, n-1);
  for (int i = 0; i < n; i++)
  {
  	cout << arr[i] << endl;
  }
return 0;
}