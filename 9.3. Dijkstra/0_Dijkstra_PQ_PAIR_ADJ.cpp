//Dijkstra's algorithm solves the shortest-path problem for any weighted, 
//directed graph with non-negative weights. It can handle graphs consisting
// of cycles, but negative weights will cause this algorithm to produce incorrect results.


#include<bits/stdc++.h>
//Time complexity: O(E+vlogv)
using namespace std;
#define INF 999

priority_queue<pair<int,int>> PQ;
int destance[999]; 
vector<pair<int,int>> adjListPair[INF];
int node, edge;

void adjListPairInput();
void adjListPairPrint(int node);
void dijkstra(int source);




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
	for(int i = 0; i < node; i++){
	 destance[i] = 999;
	  }
	destance[source] = 0;
	PQ.push(make_pair(source, destance[source]));

    string color[INF];
    for(int i = 0; i < node; i++){ color[i] = "white"; }
    color[source] = "gray";

    int nodeCount = 0;

    char bfsSequence[INF];
	bfsSequence[nodeCount++] = source + 'a';

	char nodeName = source + 'a';
	int step = 1;
	cout << "\n Step " << step << " :\n" << " Visited = " << " (" << nodeName << ", " << destance[source] << ") " << ", Color = " << color[source] << endl;
    cout << " Queue = " << " (" << nodeName << ", " << destance[source] << ") " << endl; 
	cout << " after Updating Distance: ";
	for(int i = 0; i < node; i++){ 
		nodeName = i + 'a';
		cout << "(" << nodeName << ", " << destance[i] << ")";
		if(i+1 != node){ cout << ", "; }
	}
	cout << endl;
	// getchar();
    while(!PQ.empty())
    {
    	bool updateConfirm = 0;
        int pqCurrentFrontNode = PQ.top().first;
        int pqCurrentFrontdestance = PQ.top().second;
        PQ.pop();

        color[pqCurrentFrontNode] = "black";
        nodeName = pqCurrentFrontNode + 'a';
        step++;
        nodeName = pqCurrentFrontNode + 'a';
		cout << "\n Step " << step << " :" << endl << " Popped  = " << "(" << nodeName << ", " << -pqCurrentFrontdestance << ") " << ", Color = " << color[pqCurrentFrontNode] << endl;
		// cout << "Before Updating Distance: ";
		// for(int i = 0; i < node; i++){ 
		// 	nodeName = i + 'a';
		// 	cout << "(" << nodeName << ", " << destance[i] << ")  ";   
		// }
		// getchar();
        for(int i=0; i < adjListPair[pqCurrentFrontNode].size(); i++)
        {
            int qFrontElementsNode = adjListPair[pqCurrentFrontNode][i].first;
            int qFrontToElementsdestance = adjListPair[pqCurrentFrontNode][i].second;

            	if(destance[qFrontElementsNode] > destance[pqCurrentFrontNode] + qFrontToElementsdestance){
				bfsSequence[nodeCount++] = qFrontElementsNode + 'a'; 
				destance[qFrontElementsNode] = destance[pqCurrentFrontNode] + qFrontToElementsdestance;
            	color[qFrontElementsNode] = "gray";

            	PQ.push(make_pair(qFrontElementsNode, -destance[qFrontElementsNode]));

            	nodeName = qFrontElementsNode + 'a';
				cout << " Visited = " << "(" << nodeName << ", " << destance[qFrontElementsNode] << ") " << ", Color = " << color[qFrontElementsNode] << endl; 
            	updateConfirm = 1;
            }
        }
        if(updateConfirm){
        	cout << " after Updating Distance: ";
			for(int i = 0; i < node; i++){ 
				nodeName = i + 'a';
				cout << "(" << nodeName << ", " << destance[i] << ")";
				if(i+1 != node){ cout << ", "; }
			}
			cout << endl;
			// getchar();
		} else {
			cout << " No node Distance updated in this step.";
			cout << endl;
			// getchar();
		}
    }
    cout << "\n BFS node update sequence  ";
    int levelIndex;
    for(int i=0; i < nodeCount; i++){ 
    cout << " -> " << bfsSequence[i];
    levelIndex = bfsSequence[i] - 'a';
    }
    cout << endl;
    for(int i = 0; i < node; i++){
    	nodeName = i + 'a';
    	cout << " Minimum destance of: " << nodeName << " = " << destance[i] << endl;
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

 Minimum destance of: a = 0
 Minimum destance of: b = 2
 Minimum destance of: c = 3
 Minimum destance of: d = 5
 Minimum destance of: e = 6
*/