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
	queue<int> Q, Q2;
	Q.push(source);

    string color[INF];
    for(int i = 0; i < node; i++){ color[i] = "white"; }
    color[source] = "gray";

    int level[INF];
    level[source] = 0;

    int nodeCount = 0;

    char bfsSequence[INF];
	bfsSequence[nodeCount++] = source + 'a';

	char nodeName = source + 'a';
	int step = 1;
	cout << "\n Step " << step << " :\n" << " Visited = " << nodeName << ", Color = " << color[source] << endl;
    cout << " Queue = " << nodeName << endl << endl; 

    while(!Q.empty())
    {
        int qFrontCurrent = Q.front();
        Q.pop();
        color[qFrontCurrent] = "black";

        nodeName = qFrontCurrent + 'a';

        step++;
		cout << " Step " << step << " :" << endl << " Popped  = " << nodeName << ", Color = " << color[qFrontCurrent] << endl;

        for(int i=0; i < adjList[qFrontCurrent].size(); i++)
        {
            int qFrontElements = adjList[qFrontCurrent][i];
            if(color[qFrontElements] == "white"){
				bfsSequence[nodeCount++] = qFrontElements + 'a'; 

            	color[qFrontElements] = "gray";

            	level[qFrontElements] = level[qFrontCurrent] + 1;

            	Q.push(qFrontElements);

            	nodeName = qFrontElements + 'a';
				cout << " Visited = " << nodeName << ", Color = " << color[qFrontElements] << endl;
    			  
            	if(qFrontElements == destination){
            			Q2 = Q;
						cout << " Current Queue: ";
						while(!Q2.empty()){
							nodeName = Q2.front() + 'a';
							cout << nodeName << " ";
        					Q2.pop();
						}
						cout << endl << endl;
            		while(!Q.empty()){
            			int popped = Q.front();
            			Q.pop();
            			nodeName = popped + 'a';
            			color[popped] = "black";
            			step++;
						cout << "\n Step " << step << " :" << endl << " Popped  = " << nodeName << ", Color = " << color[popped] << endl;
            			Q2 = Q;
						cout << " Current Queue: ";
						while(!Q2.empty()){
							nodeName = Q2.front() + 'a';
							cout << nodeName << " ";
        					Q2.pop();
						}

						cout << endl << endl;
            		}
            		break;
            	}

            }
        }

        Q2 = Q;
        if(!Q2.empty()){
		cout << " Current Queue: ";
		while(!Q2.empty()){
			nodeName = Q2.front() + 'a';
			cout << nodeName << " ";
        	Q2.pop();
		}
		cout << endl << endl;
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