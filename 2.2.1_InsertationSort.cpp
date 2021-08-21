#include<bits/stdc++.h> 
using namespace std;

void insertion_sort(int array[], int n) {
    for(int i = 1; i < n; i++){
      int key = array[i];
      int j = i - 1;
      while( j >= 0 && array[j] > key) { //array[j] > key = '>' is for ascending order & '<' is for descending order, rest is same
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = key;
  }
  }
  
  int main(){
  	int n, a[100009];
  	cin >> n;
  	for(int i=0;i<n;i++)
		cin>>a[i];
	insertion_sort(a, n);
	for(int i=0;i<n;i++)
		cout << a[i] << "\t";	
  }
