#include<iostream>
#include<algorithm>
using namespace std;

struct Map3D{
	char id;
	int deadline, profit;
};

bool compare(Map3D job1, Map3D job2){
	return job1.profit > job2.profit;
}

int main(){
	Map3D arr[10000];
	int tJob;
	cin >> tJob;
	
	for(int i = 0; i < tJob; i++){
		cin >> arr[i].id;
		cin >> arr[i].deadline >> arr[i].profit;
	}
	
	sort(arr, arr+tJob, compare);
	
	int result[tJob]; 
    bool slot[tJob];
    int profit = 0;
    
    for(int i = 0; i < tJob; i++){
    	slot[i] = false;
    }
    cout << endl << "Sorted 3D data:" << endl;
	for(int i = 0; i < tJob; i++){
	cout << arr[i].id << " ";
	cout << arr[i].deadline << " " << arr[i].profit << endl;
	for(int j = arr[i].deadline; j > 0; j--){
		if(slot[j] == false){
			result[j] = i;  // Add this job to result
             slot[j] = true; // Make this slot occupied
             profit += arr[i].profit;
			 break;
		}
	}
	}
	cout << endl << "Sequenced Result: " << endl;
	for (int i=0; i<tJob; i++){
	       if (slot[i]){
         cout << arr[result[i]].id << " ";
         cout << arr[result[i]].deadline << " ";
         cout << arr[result[i]].profit << endl;
     }
}
	cout << "Total Profit: " << profit;
	return 0;
}
