#include <bits/stdc++.h>
using namespace std;


void quickSortAccend(int array[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot){
            i++;
        }            
        while (array[j] > pivot){
            j--;
        }
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSortAccend(array, low, j);
    if (i < high)
        quickSortAccend(array, i, high);
}


double quickSortAccending(){
	int array[100005], n;
      cin >> n;
       for (int i = 0; i < n; i++)
        {
        	cin >> array[i];
      	}
      	clock_t sortStart = clock();
	    quickSortAccend(array, 0, n-1);
	    clock_t sortEnd = clock();
    double sortTime = (double)(sortEnd-sortStart)/CLOCKS_PER_SEC;
	  for (int i = 0; i < n; i++){
        cout << array[i] << endl;
    }
    //cout << endl << "Accending Order quick sort time: " << sortTime << " second"<< endl;
	return sortTime;
	}



void quickSortDecend(int array[], int low, int high){
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] > pivot){
            i++;
        }   
        while (array[j] < pivot){
            j--;
        }
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low){
        quickSortDecend(array, low, j);
    }
    if (i < high){
        quickSortDecend(array, i, high);
    }
}

double quickSortDecending(){
	int array[100005], n;
      cin >> n;
       for (int i = 0; i < n; i++)
        {
        	cin >> array[i];
      	}
      	clock_t sortStart = clock();
	    quickSortDecend(array, 0, n-1);
	    clock_t sortEnd = clock();
    double sortTime = (double)(sortEnd-sortStart)/CLOCKS_PER_SEC;
	  for (int i = 0; i < n; i++){
        cout << array[i] << endl;
    }
    //cout << endl << "Decending Order quick sort time: " << sortTime << " second"<< endl;
	return sortTime;
	}

int main(int argc, char const *argv[])
{
    quickSortAccending();
    quickSortDecending();
    return 0;
}