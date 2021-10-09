// Name: Md. Rakibul Hasan
// ID: 2020000000144

#include<bits/stdc++.h> 
using namespace std; 

double bubbleSortAccending();
double bubbleSortDecending();

double insertSortAccending();
double insertSortDecending();

double mergeSortAccending();
void mergeSortAccend(int arr[], int lo, int hi);
void mergeAccend(int arr[], int lo, int mid, int hi);
double mergeSortDecending();
void mergeSortDecend(int arr[], int lo, int hi);
void mergeDecend(int arr[], int lo, int mid, int hi);

double quickSortAccending();
void quickSortAccend(int array[], int low, int high);
double quickSortDecending();
void quickSortDecend(int array[], int low, int high);

double bubbleSortInp1_AcTime = 10000, bubbleSortInp2_AcTime = 10000, bubbleSortInp3_AcTime = 10000;
double bubbleSortInp1_DcTime= 10000, bubbleSortInp2_DcTime= 10000, bubbleSortInp3_DcTime = 10000;
double insertSortInp1_AcTime= 10000, insertSortInp2_AcTime= 10000, insertSortInp3_AcTime = 10000;
double insertSortInp1_DcTime= 10000, insertSortInp2_DcTime= 10000, insertSortInp3_DcTime = 10000;
double mergeSortInp1_AcTime= 10000, mergeSortInp2_AcTime= 10000, mergeSortInp3_AcTime	   = 10000;
double mergeSortInp1_DcTime= 10000, mergeSortInp2_DcTime= 10000, mergeSortInp3_DcTime	   = 10000;
double quickSortInp1_AcTime= 10000, quickSortInp2_AcTime= 10000, quickSortInp3_AcTime	   = 10000;
double quickSortInp1_DcTime= 10000, quickSortInp2_DcTime= 10000, quickSortInp3_DcTime	   = 10000;

void generateReport();


void bubbleSortAccending1(){
	freopen("input1.txt","r",stdin);
    freopen("bubbleSortAccending_Input1.txt","w",stdout);
    bubbleSortInp1_AcTime = bubbleSortAccending();
}


void bubbleSortAccending2(){
	freopen("input2.txt","r",stdin);
    freopen("bubbleSortAccending_Input2.txt","w",stdout);
    bubbleSortInp2_AcTime = bubbleSortAccending();
}

void bubbleSortAccending3(){
	freopen("input3.txt","r",stdin);
    freopen("bubbleSortAccending_Input3.txt","w",stdout);
    bubbleSortInp3_AcTime = bubbleSortAccending();    
}

void bubbleSortDecending1(){
	freopen("input1.txt","r",stdin);
    freopen("bubbleSortDecending_Input1.txt","w",stdout);
    bubbleSortInp1_DcTime = bubbleSortDecending();
}

void bubbleSortDecending2(){
	freopen("input2.txt","r",stdin);
    freopen("bubbleSortDecending_Input2.txt","w",stdout);
    bubbleSortInp2_DcTime = bubbleSortDecending();
}

void bubbleSortDecending3(){
	freopen("input3.txt","r",stdin);
    freopen("bubbleSortDecending_Input3.txt","w",stdout);
    bubbleSortInp3_DcTime = bubbleSortDecending();
}

void insertSortAccending1(){
	freopen("input1.txt","r",stdin);
    freopen("insertSortAccending_Input1.txt","w",stdout);
    insertSortInp1_AcTime = insertSortAccending();
}


void insertSortAccending2(){
	freopen("input2.txt","r",stdin);
    freopen("insertSortAccending_Input2.txt","w",stdout);
    insertSortInp2_AcTime = insertSortAccending();
}

void insertSortAccending3(){
	freopen("input3.txt","r",stdin);
    freopen("insertSortAccending_Input3.txt","w",stdout);
    insertSortInp3_AcTime = insertSortAccending();    
}

void insertSortDecending1(){
	freopen("input1.txt","r",stdin);
    freopen("insertSortDecending_Input1.txt","w",stdout);
    insertSortInp1_DcTime = insertSortDecending();
}

void insertSortDecending2(){
	freopen("input2.txt","r",stdin);
    freopen("insertSortDecending_Input2.txt","w",stdout);
    insertSortInp2_DcTime = insertSortDecending();
}

void insertSortDecending3(){
	freopen("input3.txt","r",stdin);
    freopen("insertSortDecending_Input3.txt","w",stdout);
    insertSortInp3_DcTime = insertSortDecending();
}

void mergeSortAccending1(){
	freopen("input1.txt","r",stdin);
    freopen("mergeSortAccending_Input1.txt","w",stdout);
    mergeSortInp1_AcTime = mergeSortAccending();
}

void mergeSortAccending2(){
	freopen("input2.txt","r",stdin);
    freopen("mergeSortAccending_Input2.txt","w",stdout);
    mergeSortInp2_AcTime = mergeSortAccending();
}

void mergeSortAccending3(){
	freopen("input3.txt","r",stdin);
    freopen("mergeSortAccending_Input3.txt","w",stdout);
    mergeSortInp3_AcTime = mergeSortAccending();	
}

void mergeSortDecending1(){
	freopen("input1.txt","r",stdin);
    freopen("mergeSortDecending_Input1.txt","w",stdout);
    mergeSortInp1_DcTime = mergeSortDecending();
}

void mergeSortDecending2(){
	freopen("input2.txt","r",stdin);
    freopen("mergeSortDecending_Input2.txt","w",stdout);
    mergeSortInp2_DcTime = mergeSortDecending();
}

void mergeSortDecending3(){
	freopen("input3.txt","r",stdin);
    freopen("mergeSortDecending_Input3.txt","w",stdout);
    mergeSortInp3_DcTime = mergeSortDecending();
}

void quickSortAccending1(){
	freopen("input1.txt","r",stdin);
    freopen("quickSortAccending_Input1.txt","w",stdout);
    quickSortInp1_AcTime = quickSortAccending();
}

void quickSortAccending2(){
	freopen("input2.txt","r",stdin);
    freopen("quickSortAccending_Input2.txt","w",stdout);
    quickSortInp2_AcTime = quickSortAccending();
}

void quickSortAccending3(){
	freopen("input3.txt","r",stdin);
    freopen("quickSortAccending_Input3.txt","w",stdout);
    quickSortInp3_AcTime = quickSortAccending();
}

void quickSortDecending1(){
	freopen("input1.txt","r",stdin);
    freopen("quickSortDecending_Input1.txt","w",stdout);
    quickSortInp1_DcTime = quickSortDecending();
}
 
void quickSortDecending2(){
	freopen("input2.txt","r",stdin);
    freopen("quickSortDecending_Input2.txt","w",stdout);
    quickSortInp2_DcTime = quickSortDecending();
}

void quickSortDecending3(){
	freopen("input3.txt","r",stdin);
    freopen("quickSortDecending_Input3.txt","w",stdout);
    quickSortInp3_DcTime = quickSortDecending();
}

void reportFile(){
	generateReport();
}

int main(){
	bubbleSortAccending1();
//	bubbleSortAccending2();
//	bubbleSortAccending3();
	bubbleSortDecending1();
//	bubbleSortDecending2();
//	bubbleSortDecending3();
	
	insertSortAccending1();
	insertSortAccending2();
	insertSortAccending3();
	insertSortDecending1();
	insertSortDecending2();
	insertSortDecending3();
	
	mergeSortAccending1();
	mergeSortAccending2();
	mergeSortAccending3();
	mergeSortDecending1();
	mergeSortDecending2();
	mergeSortDecending3();
	
    quickSortAccending1();
    quickSortAccending2();
    quickSortAccending3();
    quickSortDecending1();
    quickSortDecending2();
    quickSortDecending3();
    
    reportFile();
    
	return 0;
}


double bubbleSortAccending(){
	int n, arr[100005];
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }
    clock_t sortStart = clock();
    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i; j++) {
    	if(arr[j] > arr[j+1]){
    			 temp = arr[j+1];
                 arr[j+1] = arr[j];
                 arr[j] = temp;
             }
    	}
	}
	clock_t sortEnd = clock();
    double sortTime = (double) (sortEnd-sortStart)/CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++) {
                cout << arr[i] << "\n";
        }
    //cout << endl << "Accending Order Bubble sort time: " << sortTime << " second"<< endl;
	return sortTime;
}


double bubbleSortDecending(){
	int n, arr[100005];
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }
    clock_t sortStart = clock();
    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i; j++) {
    	if(arr[j] < arr[j+1]){
    			 temp = arr[j+1];
                 arr[j+1] = arr[j];
                 arr[j] = temp;
             }
    	}
	}
	clock_t sortEnd = clock();
    double sortTime = (double) (sortEnd-sortStart)/CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++) {
                cout << arr[i] << "\n";
        }
    //cout << endl << "Decending Order Bubble sort time: " << sortTime << " second"<< endl;
	return sortTime;
	}
	
	double insertSortAccending(){
	int n, arr[100005];
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }
        int key, j;
    clock_t sortStart = clock();
    for(int i = 1; i < n; i++){
      key = arr[i];
      j = i - 1;
      while( j >= 0 && arr[j] > key) { //array[j] > key = '>' is for ascending order & '<' is for descending order, rest is same
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
  }
	clock_t sortEnd = clock();
    double sortTime = (double) (sortEnd-sortStart)/CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++) {
                cout << arr[i] << "\n";
        }
    cout << endl << "Accending Order insert sort time: " << sortTime << " second"<< endl;
	return sortTime;
}

double insertSortDecending(){
	int n, arr[100005];
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }
        int key, j;
    clock_t sortStart = clock();
    for(int i = 1; i < n; i++){
      key = arr[i];
      j = i - 1;
      while( j >= 0 && arr[j] < key) { //array[j] > key = '>' is for ascending order & '<' is for descending order, rest is same
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
  }
	clock_t sortEnd = clock();
    double sortTime = (double) (sortEnd-sortStart)/CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++) {
                cout << arr[i] << "\n";
        }
    cout << endl << "Accending Order insert sort time: " << sortTime << " second"<< endl;
	return sortTime;
}

double mergeSortAccending(){
  int arr[100005], n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
  	cin >> arr[i];
  }
  	clock_t sortStart = clock();
	mergeSortAccend(arr, 0, n-1);
	clock_t sortEnd = clock();
    double sortTime = (double) (sortEnd-sortStart)/CLOCKS_PER_SEC;
  for (int i = 0; i < n; i++)
  {
  	cout << arr[i] << endl;
  }
  //cout << endl << "Accending Order merge sort time: " << sortTime << " second"<< endl;
	return sortTime;
	}

void mergeAccend(int arr[], int lo, int mid, int hi){
	int temp[100005], k = 0, i = lo, j = mid+1;
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

double mergeSortDecending(){
  int arr[100005], n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
  	cin >> arr[i];
  }
  	clock_t sortStart = clock();
	mergeSortDecend(arr, 0, n-1);
	clock_t sortEnd = clock();
    double sortTime = (double)(sortEnd-sortStart)/CLOCKS_PER_SEC;
  for (int i = 0; i < n; i++)
  {
  	cout << arr[i] << endl;
  }
  //cout << endl << "Decending Order merge sort time: " << sortTime << " second"<< endl;
   return sortTime;
	}

void mergeSortDecend(int arr[], int lo, int hi){	
	if(lo == hi){
		return;
	}
	int mid = (lo + hi)/2;
	mergeSortDecend(arr, lo, mid);
	mergeSortDecend(arr, mid+1, hi);
	mergeDecend(arr, lo, mid, hi);	
}

void mergeDecend(int arr[], int lo, int mid, int hi){
	int temp[100005], k = 0, i = lo, j = mid+1;
	while(i <= mid && j <= hi){
		if(arr[i] > arr[j]){
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

void generateReport(){
	freopen("ReportFileOfSortingAlgo.txt","w",stdout);
	cout << "Input 1:" << endl;
	cout << "Bubble Sort: = Ascending : " << bubbleSortInp1_AcTime << "s, Descending : " << bubbleSortInp1_DcTime << "s" << endl;
	cout << "Insert Sort: = Ascending : " << insertSortInp1_AcTime << "s, Descending : " << insertSortInp1_DcTime << "s" << endl;
	cout << "Merge Sort: = Ascending : " << mergeSortInp1_AcTime << "s, Descending : " << mergeSortInp1_DcTime << "s" << endl;
	cout << "Quick Sort: = Ascending : " << quickSortInp1_AcTime << "s, Descending : " << quickSortInp1_DcTime << "s" << endl;
	cout << "Best Sorting: = Ascending : ";
	if(bubbleSortInp1_AcTime < insertSortInp1_AcTime && bubbleSortInp1_AcTime < mergeSortInp1_AcTime && bubbleSortInp1_AcTime < quickSortInp1_AcTime){
		cout << "Bubble Sort";
	} else if(insertSortInp1_AcTime < mergeSortInp1_AcTime && insertSortInp1_AcTime < quickSortInp1_AcTime){
		cout << "Insertion Sort";
	} else if(mergeSortInp1_AcTime < quickSortInp1_AcTime){
		cout << "Merge Sort";
	} else {
		cout << "Quick Sort";
	}
	cout << ", Descending: ";
	if(bubbleSortInp1_DcTime < insertSortInp1_DcTime && bubbleSortInp1_DcTime < mergeSortInp1_DcTime && bubbleSortInp1_DcTime < quickSortInp1_DcTime){
		cout << "Bubble Sort";
	} else if(insertSortInp1_DcTime < mergeSortInp1_DcTime && insertSortInp1_DcTime < quickSortInp1_DcTime){
		cout << "Insertion Sort";
	} else if(mergeSortInp1_DcTime < quickSortInp1_DcTime){
		cout << "Merge Sort";
	} else {
		cout << "Quick Sort";
	}
	cout << endl << endl << endl;
	
	cout << "Input 2:" << endl;
	cout << "Bubble Sort: = Ascending : " << bubbleSortInp2_AcTime << "s, Descending : " << bubbleSortInp2_DcTime << "s" << endl;
	cout << "Insert Sort: = Ascending : " << insertSortInp2_AcTime << "s, Descending : " << insertSortInp2_DcTime << "s" << endl;
	cout << "Merge Sort: = Ascending : " << mergeSortInp2_AcTime << "s, Descending : " << mergeSortInp2_DcTime << "s" << endl;
	cout << "Quick Sort: = Ascending : " << quickSortInp2_AcTime << "s, Descending : " << quickSortInp2_DcTime << "s" << endl;
	cout << "Best Sorting: = Ascending : ";
	if(bubbleSortInp2_AcTime < insertSortInp2_AcTime && bubbleSortInp2_AcTime < mergeSortInp2_AcTime && bubbleSortInp2_AcTime < quickSortInp2_AcTime){
		cout << "Bubble Sort";
	} else if(insertSortInp2_AcTime < mergeSortInp2_AcTime && insertSortInp2_AcTime < quickSortInp2_AcTime){
		cout << "Insertion Sort";
	}else if(mergeSortInp2_AcTime < quickSortInp2_AcTime){
		cout << "Merge Sort";
	} else {
		cout << "Quick Sort";
	}
	cout << ", Descending: ";
	if(bubbleSortInp2_DcTime < insertSortInp2_DcTime && bubbleSortInp2_DcTime < mergeSortInp2_DcTime && bubbleSortInp2_DcTime < quickSortInp2_DcTime){
		cout << "Bubble Sort";
	} else if(insertSortInp2_DcTime < mergeSortInp2_DcTime && insertSortInp2_DcTime < quickSortInp2_DcTime){
		cout << "Insertion Sort";
	} else if(mergeSortInp2_DcTime < quickSortInp2_DcTime){
		cout << "Merge Sort";
	} else {
		cout << "Quick Sort";
	}
	cout << endl << endl << endl;
	
	
	cout << "Input 3:" << endl;
	cout << "Bubble Sort: = Ascending : " << bubbleSortInp3_AcTime << "s, Descending : " << bubbleSortInp3_DcTime << "s" << endl;
	cout << "Insert Sort: = Ascending : " << insertSortInp3_AcTime << "s, Descending : " << insertSortInp3_DcTime << "s" << endl;
	cout << "Merge Sort: = Ascending : " << mergeSortInp3_AcTime << "s, Descending : " << mergeSortInp3_DcTime << "s" << endl;
	cout << "Quick Sort: = Ascending : " << quickSortInp3_AcTime << "s, Descending : " << quickSortInp3_DcTime << "s" << endl;
	cout << "Best Sorting: = Ascending : ";
	if(bubbleSortInp3_AcTime < insertSortInp3_AcTime && bubbleSortInp3_AcTime < mergeSortInp3_AcTime && bubbleSortInp3_AcTime < quickSortInp3_AcTime){
		cout << "Bubble Sort";
	} else if(insertSortInp3_AcTime < mergeSortInp3_AcTime && insertSortInp3_AcTime < quickSortInp3_AcTime){
		cout << "Insertion Sort";
	} else if(mergeSortInp3_AcTime < quickSortInp3_AcTime){
		cout << "Merge Sort";
	} else {
		cout << "Quick Sort";
	}
	cout << ", Descending: ";
	if(bubbleSortInp3_DcTime < insertSortInp3_DcTime && bubbleSortInp3_DcTime < mergeSortInp3_DcTime && bubbleSortInp3_DcTime < quickSortInp3_DcTime){
		cout << "Bubble Sort";
	} else if(insertSortInp3_DcTime < mergeSortInp3_DcTime && insertSortInp3_DcTime < quickSortInp3_DcTime){
		cout << "Insertion Sort";
	} else if(mergeSortInp3_DcTime < quickSortInp3_DcTime){
		cout << "Merge Sort";
	} else {
		cout << "Quick Sort";
	}
	cout << endl << endl << endl;
}

