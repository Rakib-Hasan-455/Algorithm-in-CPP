#include <iostream>

using namespace std;

int fibonacci(int n){
	if(n <= 1){
		return n;
	} else {
		return fibonacci(n-1) + fibonacci(n-2); //return the last element of fibonacci series
	} 
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int lastFibo = fibonacci(n);
	cout << "Last fibonacci = " << lastFibo << endl;
	return 0;
}