#include<bits/stdc++.h>
#define INF 999
using namespace std;

int adjMatrix[INF][INF];
vector<int> adjList[INF];
int node, edge;

void adjListPrint(int node);

void adjListInput(){
	
	cin >> node >> edge;
	 
	for(int i = 0; i < edge; i++){
		char node1, node2;
		cin >> node1 >> node2;
		int node1Index = tolower(node1) - 'a';
		int node2Index = tolower(node2) - 'a';
		adjList[node1Index].push_back(node2Index);
		adjList[node2Index].push_back(node1Index);
	}
	//adjListPrint(node);
}





void BFS(int source, int destination)
{
	queue<int> Q;
    bool visited[INF] = {false};
    visited[source] = 1;
    int level[INF];
    level[source] = 0;
    Q.push(source);
    int nodeCount = 0;
    char bfsSequence[INF];
	bfsSequence[nodeCount] = source + 'a';
	nodeCount++;
    while(!Q.empty())
    {
        int qFrontCurrent = Q.front();
        Q.pop();

        for(int i=0;i<adjList[qFrontCurrent].size();i++)
        {
            int qFrontElements = adjList[qFrontCurrent][i];
            if(visited[qFrontElements] == false){
				bfsSequence[nodeCount++] = qFrontElements + 'a';
            	visited[qFrontElements] = true;
            	level[qFrontElements] = level[qFrontCurrent] + 1;
            	Q.push(qFrontElements);
            	if(qFrontElements == destination){
            		while(!Q.empty()){
            			Q.pop();
            		}
            		break;
            	}
            }
        }
    }

    cout << "BFS node visiting sequence  ";
    int levelIndex;
    for(int i=0;i<nodeCount;i++)
    { 
    cout << " -> " << bfsSequence[i];
    levelIndex = bfsSequence[i] - 'a';
    }
    cout << "\nMinimum distance: " << level[levelIndex] << endl;
}


int main(){
	adjListInput();
	char source, destination;
	cout << "Enter source: ";
	cin >> source;
	cout << "Enter destination: ";
	cin >> destination;
	int sourceIndex 	 = tolower(source) - 'a';
	int destinationIndex = tolower(destination) - 'a';
	BFS(sourceIndex, destinationIndex);
	return 0;
}


void adjListPrint(int node){
	cout << "Adjacancy List: " << endl;
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

/*
5 8
a b
a c
a d
b d
b e
b c
c e
d e
*/