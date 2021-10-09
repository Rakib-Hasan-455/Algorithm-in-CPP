#include <iostream>

using namespace std;

void towerOfHanoi(int n, char from, char to, char rem){
	if(n == 1){
		cout << "Moved disk " << n << " from " << from << " to " << to << endl;
		return;
	}
	towerOfHanoi(n-1, from, rem, to);
	cout << "Moved disk " << n << " from " << from << " to " << to << endl;
	towerOfHanoi(n-1, rem, to, from);	
}



int main(int argc, char const *argv[])
{
	int n;
	cout << "No of disks: ";
	cin >> n;
	char fromRod, toRod, remRod;
	cout << "Start from: ";
	cin >> fromRod;
	cout << "Shift to: ";
	cin >> toRod;
	cout << "Remind rod: ";
	cin >> remRod;
	towerOfHanoi(n, fromRod, toRod, remRod);
	return 0;
}