#include<bits/stdc++.h>
//Time complexity: O(E+vlogv)
using namespace std;
#define INF 999

priority_queue<pair<int,int>> PQ;
int destance[999];
int vis[INF];
int T = 0;

void adjListPairInput();
void adjListPairPrint(int node);
void dijkstra(int source);

vector<pair<int,int>> adjListPair[INF];
int node, edge;



int main(int argc, char const *argv[])
{
	adjListPairInput();
	char source;
	cout << " Source: ";
	cin >> source;
	int sourceIndex = source - 'a';
	dijkstra(sourceIndex);
	return 0;
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

void dijkstra(int source){
 	for(int i = 0; i < node; i++){	 destance[i] = 999;	  }

	destance[source] = 0;
	PQ.push(make_pair(source, destance[source]));

   
    while(!PQ.empty())
    {
    	int val = PQ.top().first;
        int cost = PQ.top().second;
        PQ.pop();

        if (vis[val] == 1) continue; // if visited, then we do not work with that node

         // cost is finalized here
        vis[val] = 1;

 		for (int i = 0; i < adjListPair[val].size(); i++){
            int nxt = adjListPair[val][i].first;
            int nxtCost = adjListPair[val][i].second;

            if (vis[nxt] == 0 && (destance[nxt] > cost + nxtCost)){
            	destance[nxt] = cost + nxtCost;
                PQ.push(make_pair(nxt, -destance[val]));
            }
        }
    }
     for (int i = 0; i < node; i++){
     	char nodeName = i + 'a';
        cout << "Node: " << nodeName << " Distance: ";
        if (destance[i] == 999) cout << "inf" << "\n";
        else cout << destance[i] << "\n";
    }
}

/*
5 6
a b 2
a c 8
a d 5
b c 1
c e 3
d e 4
a

5 6
1 2 2
1 3 8
1 4 5
2 3 1
3 5 3
4 5 4
1

*/