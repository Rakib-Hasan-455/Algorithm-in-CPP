#include<bits/stdc++.h>
#include <string>     // std::string, std::to_string
 // Time Complexity:  (v+e)


using namespace std;
#define INF 999

vector<int> adjList[INF];
bool visited[INF];

int node, edge;

void adjListPrint(int node);
void dfsVisit(int source); 

void adjListInput(){
	cout << " Number of node: ";
	cin >> node;
	cout << " Number of edge: ";
	cin >> edge;
	cout << " Enter connected nodes: " << endl;
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

int totalTime = 0;
int discoverTime[INF], finishTime[INF];
string color[INF];
char DFSSequence[INF];
int nodeCount = 0;
string stepString = "";

void dfs(int source){
    // visited[source] = 1;
    for(int i = 0; i < 999; i++){ color[i] = "white"; }
    totalTime++;
    discoverTime[source] = totalTime;

    color[source] = "gray";
    
    char nodeName = source + 'a';
   	string tempNodeName = "";
    tempNodeName += nodeName;
    DFSSequence[nodeCount++] = nodeName;

    stepString  += " Step " + to_string(totalTime) + " :\n";
    stepString  += " Visited: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";

    for (int i = 0; i < adjList[source].size(); i++){
        int next = adjList[source][i];
        if (color[next] == "white"){
            dfsVisit(next);
            totalTime++;
            finishTime[source] = totalTime;
            color[source] = "black"; 
            stepString  += " Step " + to_string(totalTime) + " :\n";
 			stepString  += " Back Visited to: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";
        }
    }
}



void DFSSequencePrint(){

	cout << endl << stepString << endl;
	cout << " Final DFS visiting sequence ";
	for(int i = 0; i < nodeCount; i++){
		cout << " -> " << DFSSequence[i];
	}
	cout << "\n Total DFS visiting time: " << totalTime << endl;
}

int main()
{
    adjListInput();
    dfs(0);
    DFSSequencePrint();
    return 0;
}

void adjListPrint(int node){
	cout << "\n Adjacancy List: " << endl;
	for (int i = 0; i < node; ++i)
	{
		char listName = 'a'+i;
		cout << " " << listName << " : ";
		for (int j = 0; j < adjList[i].size() ; j++)
		{
			char listElements = adjList[i][j] + 'a';
			cout << listElements << " ";
		} 
		cout << endl;
	}
}

void dfsVisit(int source){
	totalTime++;
    discoverTime[source] = totalTime;

    color[source] = "gray";
    
    char nodeName = source + 'a';
    string tempNodeName = "";
    tempNodeName += nodeName;
    DFSSequence[nodeCount++] = nodeName;

    stepString  += " Step " + to_string(totalTime) + " :\n";
 	stepString  += " Visited: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";
        
    for (int i = 0; i < adjList[source].size(); i++){
        int next = adjList[source][i];
        if (color[next] == "white"){
            dfsVisit(next);
            totalTime++;
            finishTime[source] = totalTime;
            color[source] = "black"; 
            stepString  += " Step " + to_string(totalTime) + " :\n";
 			stepString  += " Back Visited to: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";
    
        }
    }
}
 
/*
6 8
a b
a d
b c
b d
c d
c f
c e
e f

7 9
a b
a d
b d
b c
c d
c e
e f
e g
f g
*/