#include <iostream>
#include <algorithm>
using namespace std;
const int NN = 100; // heap size

struct heap {
int myarray[NN+1]; // myarray to store the numbers as heap, 1 indexed
int n = 0; // the number of nodes in my array
//heap() { // constructor
//clear(); // we clear the heap
//}
//void clear() { // initialize the heap
//n = 0; // initially there are no nodes in the heap
//}
void insert(int K) { // inserting an element K in the heap
if( n == NN ) { // the heap is full
printf("cannot insert any more element, the heap is full\n");
return;
}
++n; // so, we have a new element, we increased n before adding
// the element because we start from index 1
myarray[n] = K; // inserted the element at the rightmost position
cout << "Inserted: " << myarray[n] << endl;
int p = n; // for keeping the current position
while( p > 1 ) { // p = 1 means we are on the root, and its a heap
int pr = p / 2; // pr is the parent of p
if( myarray[pr] > myarray[p] ) { // parent is greater than child
swap( myarray[pr], myarray[p] );
p = pr; // now the new position of the current element is pr
}
else break; // otherwise its a heap, so we can stop here
}
}
int remove() { // removing the minimum element from the heap
if( n == 0 ) { // is the heap is empty
printf("The heap is empty, cannot delete.\n");
return -1;
}
int K = myarray[1]; // first element in the heap is the minimum
myarray[1] = myarray[n]; // brought the last element in 1st position
n = n - 1;
int p = 1; // as we moved the rightmost element in index 1
while( 2 * p <= n ) { // means p has at least one child, if 2*p > n
// we are sure that p is in the last level
int ch = 2 * p; // contains the index of the child
if( 2 * p + 1 <= n ) { // right child exists
if( myarray[ch] > myarray[ch+1] ) // right child is smaller
// than left child
ch++; // ch contains the index of the right child
}
if( myarray[p] > myarray[ch] ) { // so, current node is larger
// than its child
swap(myarray[p], myarray[ch]);
p = ch; // new position of the current element
}
else break; //current node is smaller than its children, so heap
}
return K; // as we stored the minimum element in K
}
void print() { // printing the heap
cout << "Current nodes: ";
for(int i = 1; i <= n; i++){
	cout << myarray[i] << " ";
}
cout << endl;
}
};

int main() {
heap A; 
A.insert(1);
A.insert(2);
A.insert(3);
A.insert(4);
A.print();
A.remove();
A.print();
A.remove();
A.print();
//int n;
//cin >> n;
//for(int i = 0; i < n; i++){
//	cout << "1. Insert" << endl;
//	cout << "2. Find" << endl;
//	cout << "3. Delete" << endl;
//	int option;
//	cin >> option;
//	if(option == 1){
//		int value;
//		cout << "insert: ";
//		cin >> value;
//		A.insert(value);
//		A.print();
//	} else if(option == 2){
//		cout << "Current root element: " << A.myarray[1] << endl;
//	} else if(option == 3){
//		cout << A.remove() << " is deleted!" << endl;
//		A.print();
//	} else {
//		cout << "Invalid option! Try again.";
//	}
//}
return 0;
}

