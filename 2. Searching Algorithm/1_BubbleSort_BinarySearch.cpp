//Md. Rakibul Hasan
//2020000000144

#include<iostream>
#include <algorithm>

using namespace std;

void BubbleSort(int arr[], int len);
int BinarySearch(int arr[], int search, int lowerbound, int higherbound);
int BinarySearchProcess(int arr[], int search, int lowerbound, int higherbound);

//Main function drive code or to call user defined function
int main()
{
    cout << "How many elements you wanna input?" << endl;
    int len;
    cin >> len;
    int arr[len] ;
    cout << "Sample input: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    int search;
    cout << "Search key: ";
    cin >> search;
    BubbleSort(arr, len);
    BinarySearch(arr, search, 0, len-1);

    return 0;
}


void BubbleSort(int arr[], int len) {
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for (int k = 0; k < len; k++) {
        cout << arr[k];
        if(k < len - 1){
            cout << ", ";
        }
    }
    cout << endl;
}


int BinarySearch(int arr[], int search, int lowerbound, int higherbound){
    int indexFound = BinarySearchProcess(arr, search, lowerbound, higherbound);
    if(indexFound != -1){
        cout << "Search key found and index is " << indexFound << endl;
    } else {
        cout << "Search key not found!" << endl;
    }
    return 0;
}


int BinarySearchProcess(int arr[], int search, int lowerbound, int higherbound){
    while(lowerbound <= higherbound){
        int midPoint = lowerbound + (higherbound-lowerbound)/2;
        if(arr[midPoint] == search){
            return midPoint;
        } else if(search > arr[midPoint]){
            lowerbound = midPoint + 1;
        } else if(search < arr[midPoint]){
            higherbound = midPoint - 1;
        }
    }
    return -1;
}

