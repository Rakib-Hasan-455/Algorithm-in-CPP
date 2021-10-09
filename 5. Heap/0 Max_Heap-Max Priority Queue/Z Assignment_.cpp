#include <iostream>
#include <algorithm>
using namespace std;
const int NN = 100;  

struct heap {
int myarray[NN+1]; 
int n = 0;  
void insert(int K) { 
if( n == NN ) {  
printf("cannot insert any more element \n");
return;
}
++n;   
myarray[n] = K;  
int p = n;  
while( p > 1 ) { 
int pr = p / 2;  
if( myarray[pr] < myarray[p] ) {  
swap( myarray[pr], myarray[p] );
p = pr;  
}
else break; 
}
}
int remove() {  
if( n == 0 ) { 
printf(" empty cannot delete.\n");
return -1;
}
int K = myarray[1];  
myarray[1] = myarray[n];  
n = n - 1;
int p = 1;  
while( 2 * p <= n ) { 
int ch = 2 * p;  
if( 2 * p + 1 <= n ) { 
if( myarray[ch] < myarray[ch+1] ) 
ch++;  
}
if( myarray[p] < myarray[ch] ) { 
swap(myarray[p], myarray[ch]);
p = ch; 
}
else break;  
}
return K; 
}
void print() {   
for(int i = 1; i <= n; i++){
	cout << myarray[i] << " ";
}
cout << endl;
}
};

int main() {
heap A; 
int n;
cin >> n;
for(int i = 0; i < n; i++){
	cout << "1.Insert" << endl;
	cout << "2.Find" << endl;
	cout << "3.Delete" << endl;
	int option;
	cin >> option;
	if(option == 1){
		int value; 
		cin >> value;
		A.insert(value); 
	} else if(option == 2){
		cout << A.myarray[1] << endl;
	} else if(option == 3){
		cout << A.remove() << " is deleted!" << endl;
	}
}
A.print();
return 0;
}

