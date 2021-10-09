#include<iostream>
#include<algorithm>
using namespace std;

struct Map3D{
	char id;
	int start, end;
};

bool compare(Map3D job1, Map3D job2){
	return job1.end < job2.end;
}

int main(){
	Map3D arr[10000];
	int tJob;
	cin >> tJob;
	
	for(int i = 0; i < tJob; i++){
		cin >> arr[i].id;
		cin >> arr[i].start >> arr[i].end;
	}
	
	//sort(arr, arr+tJob, compare);

    int work = 0;
    string workSequence = "";
    
    cout << endl << "Sorted 3D data ascending order according to end time:" << endl;
	for(int i = 0; i < tJob; i++){
	cout << arr[i].id << " ";
	cout << arr[i].start << " " << arr[i].end << endl;
	}
	
	cout << endl << "Sequenced Result: " << endl;
	//print first work
		int j = 0;
	cout << arr[j].id << " " << arr[j].start << " " << arr[j].end << endl;
	workSequence += arr[j].id;
		work++;
		for(int i = 0; i < tJob; i++){
		if(arr[i].start >= arr[j].end){
		cout << arr[i].id << " " << arr[i].start << " " << arr[i].end << endl;
		j = i;
		
		workSequence +=  "->";
		workSequence += arr[i].id ;
		work++;
}
}
	cout << "Total work: " << work << endl;
	cout << "Work sequence: " << workSequence << endl;
	return 0;
}
