#include <iostream>

using namespace std;

int fibonacci(int n){
	if(n <= 1){
		return n;
	} 
	int fiboprev = 0;
	int fibonext = 1;
	cout << "fibonacci = ";
	for(int i = 2; i <= n; i++){
		int temp = fibonext;
		cout << fibonext << "\t";
		fibonext = fibonext + fiboprev;
		fiboprev = temp;
	}
	cout << endl;
	return fibonext; //return the last element of fibonacci series
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int lastFibo = fibonacci(n);
	cout << "Last fibonacci = " << lastFibo << endl;
	
	return 0;
}