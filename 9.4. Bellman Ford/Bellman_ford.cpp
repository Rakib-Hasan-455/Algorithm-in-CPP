#include<bits/stdc++.h>
//Time complexity: O(V*E)
using namespace std;
#define INF 999

// It can handle negative weight nodes, but can't handle negative cycle
// graphs node

int destance[INF]; 
char shortestPath[INF];
vector<pair<int,int>> adjListPair[INF];
int node, edge;

void adjListPairInput();
void adjListPairPrint(int node);
void bellman_ford(int source);
bool relaxOneMore();

int main(){
	adjListPairInput();
	char source;
	cin >> source;
	int sourceIndex = tolower(source) - 'a';
	bellman_ford(sourceIndex);
}


void adjListPairInput(){
	//cout << "Number of node: ";
	cout << " ";
	cin >> node;
	//cout << "Number of edge: ";
	cin >> edge;
	//cout << "Enter connected nodes -> weight: " << endl;
	for(int i = 0; i < edge; i++){
		cout << " ";
		char node1, node2;
		cin >> node1 >> node2;
		int node1Index = tolower(node1) - 'a';
		int node2Index = tolower(node2) - 'a';
		int destance;
		cin >> destance;
		adjListPair[node1Index].push_back(make_pair(node2Index, destance));
		// adjListPair[node2Index].push_back(make_pair(node1Index, destance));
	}
	adjListPairPrint(node);
}

void adjListPairPrint(int node){
	cout << " Adjacancy List pair: " << endl;
	for (int i = 0; i < node; ++i)
	{
		char listName = 'a'+i;
		cout << " " << listName << " : ";
		for (int j = 0; j < adjListPair[i].size() ; j++)
		{
			char pairNode = adjListPair[i][j].first + 'a';
			int pairdestance = adjListPair[i][j].second;
			cout << "(" << pairNode << ", " << pairdestance << ")";
			if(j+1 != adjListPair[i].size()){ cout << " , "; }
		} 
		cout << endl;
	}
}
bool updated;
void bellman_ford(int source){
	for(int i = 0; i < INF; i++){ destance[i] = INF; }
	destance[source] = 0;
	shortestPath[source] = source + 'a';
	for(int i = 0; i < node-1; i++){
		cout << "\nRound " << i+1 << ":\n";
		updated = false;
		for(int j = 0; j < node; j++){
			for(int k = 0; k < adjListPair[j].size(); k++){
				int parentNodeU = j;
				int parentDestU = destance[j];
				int childNodeV = adjListPair[j][k].first;
				int childDestV = adjListPair[j][k].second;
				char node1Name = parentNodeU + 'a';
				char node2Name = childNodeV + 'a'; 
				cout << " if((parentDestU("<<node1Name<<") + childDestV("<<node2Name<<") = " << parentDestU << " + " << childDestV <<  " = " << parentDestU+childDestV << ") < (destance previous childNodeV("<<node2Name<<") = " << destance[childNodeV] << "))" << endl;
				if(((parentDestU + childDestV) < destance[childNodeV])){
					destance[childNodeV] = parentDestU + childDestV;
					shortestPath[childNodeV] = childNodeV + 'a';
					cout << " = Yes, Updated destance current childNodeV("<<node2Name<<") = " << destance[childNodeV] << endl;
					updated = true;
				} else {
					cout << " = No, No update on childNodeV("<<node1Name<<") " << endl;
				}
			}
		}
		if(!updated){
			break;
		}
	}
	if(relaxOneMore()){ cout << "Negative cycle exists!" << endl; return; }
	cout << "\n Minimum Distance of all nodes: " << endl;
	for(int i = 0; i < node; i++){
		char nodeName = i + 'a';
		cout << " " << nodeName << " node Distance = " << destance[i] << endl;
	}
	cout << "shortestPath ";
	for(int i = 0; i < node; i++){
		int shortestPathIndex = shortestPath[i] - 'a';
		cout << " -> (" << shortestPath[i] << ", " << destance[shortestPathIndex] << ")";
	}
}

bool relaxOneMore(){ 
		if(updated){ cout << "relaxOneMore executed!"; };
		for(int j = 0; j < node && updated == true; j++){
			for(int k = 0; k < adjListPair[j].size(); k++){
				int parentNodeU = j;
				int parentDestU = destance[j];
				int childNodeV = adjListPair[j][k].first;
				int childDestV = adjListPair[j][k].second; 
				 if(((parentDestU + childDestV) < destance[childNodeV])){
					destance[childNodeV] = parentDestU + childDestV;
					return true;
				}
			}
		}
	return false;
}

/*
  5 8
  a b 2
  a c 3
  a d 8
  b c -3
  c e -3
  d c 7
  d e -7
  e b 6
  */