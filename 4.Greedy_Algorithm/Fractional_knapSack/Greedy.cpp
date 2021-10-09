#include<iostream>
#include<algorithm>

using namespace std;

struct items{
	double w,p,perPrice;
};

bool comp(items value1,items value2){
		return value1.perPrice>value2.perPrice;
}

int main()
{
	int n, w;
	double mProfit=0;
	cin>>n>>w;
	items item[100];
	for(int i=0;i<n;i++){
	cin  >>  item[i].w >> item[i].p;
	item[i].perPrice = item[i].p/item[i].w;
	}
	sort(&item[0], &item[n], comp);
	for(int i=0;i<n;i++){
		if(w > item[i].w){
			mProfit = mProfit + item[i].p;
			w = w - item[i].w; 
			cout << "Item - " << item[i].w << " =" << item[i].p << endl;
		} else {
			mProfit = mProfit + w*item[i].perPrice;
			cout << "Item - " << w << " =" << w*item[i].perPrice << endl;
			w = 0;
			break;
		}
	}
	cout <<"Profit:"<<mProfit;
	return 0;
}