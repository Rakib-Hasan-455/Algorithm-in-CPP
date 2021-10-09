//Name: Md. Rakibul Hasan
//ID  : 2020000000144
// Time Complexity:  (v+e)
#include<bits/stdc++.h>
#define INF 999

using namespace std;
 
vector<int> adjList[INF];
int node, edge;

void adjListPrint(int node);

void adjListInput(){
	cout << "Number of node: ";
	cin >> node;
	cout << "Number of edge: ";
	cin >> edge;
	cout << "Enter connected edges: " << endl;
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
    Q.push(source);

    bool visited[INF];
    visited[source] = 1;

    int level[INF];
    level[source] = 0;

    int nodeCount = 0;
    char bfsSequence[INF];
	bfsSequence[nodeCount++] = source + 'a';

    while(!Q.empty())
    {
        int qFrontCurrent = Q.front();
        Q.pop();

        for(int i = 0; i < adjList[qFrontCurrent].size(); i++)
        {
            int qFrontElements = adjList[qFrontCurrent][i];
            if(visited[qFrontElements] == false){
            	Q.push(qFrontElements);

				visited[qFrontElements] = true;

            	level[qFrontElements] = level[qFrontCurrent] + 1;

				bfsSequence[nodeCount++] = qFrontElements + 'a';

            	if(qFrontElements == destination){
            		while(!Q.empty()){
            			Q.pop();
            		}
            		break;
            	}
            }
            // if(dis[qFrontElements]> dis[qFrontCurrent] + 1 )
            // {
            //     dis[qFrontElements] = dis[qFrontCurrent] + 1;
            //     Q.push(qFrontElements);
            // }
        }
    }

    cout << "BFS node visiting sequence  ";
    int levelIndex;
    for(int i = 0; i < nodeCount; i++)
    { 
    cout << " -> " << bfsSequence[i];
    levelIndex = bfsSequence[i] - 'a';
    }
    int minDistance = level[levelIndex];
    cout << "\nShortest Path: ";
    for(int i = 0; i <= minDistance; i++){
    	 for(int k=0; k < edge; k++){
    	 	if(level[k] == i){
    	 		char nodeName = k + 'a';
    	 		cout << nodeName << " ";
    	 		break;
    	 	} else {
    	 		continue;
    	 	}
    	 }
    }
    cout << "\nMinimum distance: " << minDistance << endl;
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

/*
5 8
1 2
1 3
1 4
2 4
2 5
2 3
3 5
4 5
*/