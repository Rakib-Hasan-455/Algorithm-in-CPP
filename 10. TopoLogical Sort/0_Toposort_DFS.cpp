//Name: Md. Rakibul Hasan
//ID  : 2020000000144
// Time Complexity:  (v+e)

//condition: Directed Acyclic Graph = graph with no cycle.

#include<bits/stdc++.h>
#define INF 999

using namespace std;
 
 void dfsVisit(int source); 

vector<int> adjList[INF];
int node, edge;

void adjListPrint(int node);

void adjListInput(){
	//cout << "Number of node: ";
	cin >> node;
	//cout << "Number of edge: ";
	cin >> edge;
	//cout << "Enter connected edges: " << endl;
	for(int i = 0; i < edge; i++){
		char node1, node2;
		cin >> node1 >> node2;
		int node1Index = tolower(node1) - 'a';
		int node2Index = tolower(node2) - 'a';
		adjList[node1Index].push_back(node2Index);
		//adjList[node2Index].push_back(node1Index);
	}
	adjListPrint(node);
}

int totalTime = 0;
int discoverTime[INF], finishTime[INF];
string color[INF];
char DFSSequence[INF];
int nodeCount = 0;
string stepString = "";

vector<char> topoSequence;

void dfs(int source){
    // visited[source] = 1;
    totalTime++;
    discoverTime[source] = totalTime;

    color[source] = "gray";
    if(adjList[source].empty()){
        color[source] = "black";
        finishTime[source] = totalTime;
    }
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
        } else if(color[next] == "gray"){
            totalTime++;
            finishTime[source] = totalTime;
            color[source] = "black"; 
            stepString  += " Step " + to_string(totalTime) + " :\n";
            stepString  += " Back Visited to: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";
        } else if(color[next] == "black"){
            totalTime++;
            finishTime[source] = totalTime;
            color[source] = "black"; 
            stepString  += " Step " + to_string(totalTime) + " :\n";
            stepString  += " Back Visited to: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";
    }
    }
    topoSequence.push_back(nodeName);
}

void topoSort(){
    int cycle = 1, maxTime = 0;
    for(int i = 0; i < 999; i++){ color[i] = "white"; }
    for (int i = 0; i < node; i++){
        if (color[i] == "white"){
            totalTime = 0;
            stepString += "Cycle " + to_string(cycle) + ":::::\n";
            dfs(i);
            maxTime = maxTime + totalTime;
            cycle++;
        }
    }
    cout << endl << stepString << endl;
    cout << "Topological Sort Sequence ";
        reverse(topoSequence.begin(), topoSequence.end());
    for(int i = 0; i < node; i++){
        cout << " -> " << topoSequence[i];
    }
    cout << "\n Final DFS visiting sequence ";
    for(int i = 0; i < nodeCount; i++){
        cout << " -> " << DFSSequence[i];
    }
    cout << "\n Total DFS visiting time: " << maxTime << endl;
}


int main(){
	adjListInput();

	topoSort();

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


void dfsVisit(int source){
    totalTime++;
    discoverTime[source] = totalTime;

    color[source] = "gray";
    if(adjList[source].empty()){
        color[source] = "black";
        finishTime[source] = totalTime;
    }
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
        } else if(color[next] == "gray"){
            totalTime++;
            finishTime[source] = totalTime;
            color[source] = "black"; 
            stepString  += " Step " + to_string(totalTime) + " :\n";
            stepString  += " Back Visited to: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";
        } else if(color[next] == "black"){
            totalTime++;
            finishTime[source] = totalTime;
            color[source] = "black"; 
            stepString  += " Step " + to_string(totalTime) + " :\n";
            stepString  += " Back Visited to: " + tempNodeName + ", discoverTime: " + to_string(discoverTime[source]) + ", finishTime: " + to_string(finishTime[source]) + ", node color: " + color[source] + "\n\n";
        }
    }
    topoSequence.push_back(nodeName);
}
/*
5 4
c b
a b
b d
b e
*/