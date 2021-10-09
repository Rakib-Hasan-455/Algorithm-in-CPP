#include<bits/stdc++.h>
#define INF 999

using namespace std;

int adjMatrix[INF][INF];
vector<int> adjList[INF];

void adjMatrixPrint(int node){
	for (int i = 0; i < node; ++i)
	{
		for (int j = 0; j < node ; j++)
		{
			cout << adjMatrix[i][j] << " ";
		} 
		cout << endl;
	}
}

void adjMatrixInput(){
	int node, edge;
	cin >> node >> edge;
	adjMatrix[node][node];
	for(int i = 0; i < edge; i++){
		char node1, node2;
		cin >> node1 >> node2;
		int node1Index = tolower(node1) - 'a';
		int node2Index = tolower(node2) - 'a';
		adjMatrix[node1Index][node2Index] = 1;
		adjMatrix[node2Index][node1Index] = 1;
	}
	adjMatrixPrint(node);
}

void connectedAdjMatNode(){
	char node1, node2;
	cin >> node1 >> node2;
	int node1Index = tolower(node1) - 'a';
	int node2Index = tolower(node2) - 'a';
	cout << adjMatrix[node1Index][node2Index] << " " << adjMatrix[node2Index][node1Index] << endl;
	if(adjMatrix[node1Index][node2Index] == adjMatrix[node2Index][node1Index] && adjMatrix[node1Index][node2Index] == 1 && adjMatrix[node2Index][node1Index] == 1){
		cout << "They are connected!" << endl;
	} else {
		cout << "They are not connected!" << endl;
	}
}

void adjListPrint(int node){
	for (int i = 0; i < node; ++i)
	{
		char listName = 'a'+i;
		cout << listName << " : ";
		for (int j = 0; j < adjList[i].size() ; j++)
		{
			char listElements = adjList[i][j] + 'a';
			cout << listElements << " ";
		} 
		cout << endl;
	}
}

void adjListInput(){
	int node, edge;
	cin >> node >> edge;
	 
	for(int i = 0; i < edge; i++){
		char node1, node2;
		cin >> node1 >> node2;
		int node1Index = tolower(node1) - 'a';
		int node2Index = tolower(node2) - 'a';
		adjList[node1Index].push_back(node2Index);
		adjList[node2Index].push_back(node1Index);
	}
	adjListPrint(node);
}

void connectedListNode(){
	char node1, node2;
	cin >> node1 >> node2;
	int node1Index = tolower(node1) - 'a';
	int node2Index = tolower(node2) - 'a';
	bool flag = false;
	for (int i = 0; i < adjList[node1Index].size(); i++)
	{
		int listElements = adjList[node1Index][i];
		if(node2Index == listElements){
			flag = true;
		}
	}
	if(flag){
		cout << "They are connected!" << endl;
	} else {
		cout << "They are not connected!" << endl;
	}
}

int main(int argc, char const *argv[])
{
	// adjListInput();
	// connectedListNode();
	adjMatrixInput();
	while(1) connectedAdjMatNode();
	return 0;
}