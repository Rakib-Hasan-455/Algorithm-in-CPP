#include <bits/stdc++.h>
using namespace std;


int partitionAC (int array[], int low, int high){
	int pivot = array[high];    // pivot 
    int i = (low - 1);
   
    for (int j = low; j <= high - 1; j++) 
    { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (array[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(array[i], array[j]); 
        } 
    } 
    swap(array[i + 1], array[high]); 
    return (i + 1); 
}


void quickSortAccend(int array[], int low, int high)
{
    if (low < high) 
    { 
        //partition the array 
    int pivot = partitionAC(array, low, high); 
       //sort the sub arrays independently 
        quickSortAccend(array, low, pivot - 1); 
        quickSortAccend(array, pivot + 1, high); 
    } 
}



int main()
{
      int array[100005], n;
      cin >> n;
        for (int i = 0; i < n; i++)
        {
        cin >> array[i];
      	}
	quickSortAccend(array, 0, n-1);
        for (int i = 0; i < n; i++){
        cout << array[i] << endl;
    	}
    return 0;
}
