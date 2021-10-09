#include<iostream>
#include<algorithm>

using namespace std;

struct map3D{
	double weight, price, unitPrice;
	int itemName;
};

bool compare(map3D item1, map3D item2){
	return item1.unitPrice > item2.unitPrice;
}

int main(){
	freopen("input-1.txt","r",stdin);
      freopen("output.txt","w",stdout);
	int tItems;
	double weight;
	cin >> tItems >> weight;
	map3D arr[tItems];
	for(int i = 0; i < tItems; i++){
		arr[i].itemName = i+1;
		cin  >>  arr[i].weight >> arr[i].price;
		arr[i].unitPrice = arr[i].price/arr[i].weight;
	}

	sort(&arr[0], &arr[tItems], compare);
	
	double maxProfit = 0;
	cout << "Picking sequence: " << endl;
	for(int i = 0; i < tItems; i++){
		if(weight != 0){
		if(weight > arr[i].weight){
			maxProfit = maxProfit + arr[i].price;
			weight = weight - arr[i].weight; 
			cout << "Item - " << arr[i].itemName << ":" << arr[i].weight << " = " << arr[i].price << endl;
		} else {
			maxProfit = maxProfit + weight*arr[i].unitPrice;
			cout << "Item - " << arr[i].itemName << ":" << weight << " = " << weight*arr[i].unitPrice << endl;
			weight = 0;
			}
	}
	}

	cout << "Max Profit: " << maxProfit << endl;
	
	return 0;
}
