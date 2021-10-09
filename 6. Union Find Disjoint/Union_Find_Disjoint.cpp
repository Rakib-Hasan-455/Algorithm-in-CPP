//Applied on that tree where is only one root

#include<bits/stdc++.h>
using namespace std;

vector<int> dsuf;
//FIND operation
int findRoot(int v)
{
	if(dsuf[v]==-1)
		return v;
	return findRoot(dsuf[v]);
}

void check_Connection(int node1, int node2){
	int node1Root = findRoot(node1);
	int node2Root = findRoot(node2);
	if(node1Root == node2Root){
		cout << "They are Connected!\n";
	} else {
		cout << "They are not connected!\n";
	}
}

void union_op(int node1,int node2)
{
	int node1Root = findRoot(node1);
	int node2Root = findRoot(node2);
	dsuf[node1Root] = node2Root;
}

// bool isCyclic(vector<pair<int,int>>& edge_List) //only applicable in graph/to check it's graph or not
// {
// 	for(auto p: edge_List)
// 	{
// 		int fromP = findRoot(p.first);	//FIND absolute parent of subset
// 		int toP = findRoot(p.second);

// 		if(fromP == toP)
// 			return true;

// 		//UNION operation
// 		union_op(fromP,toP);	//UNION of 2 sets
// 	}
// 	return false;
// }

// void checkCycle(vector<pair<int,int>> edge_List){ //only applicable in graph/to check it's graph or not

// 	if(isCyclic(edge_List))
// 		cout<<"Graphs are Cyclic\n";
// 	else
// 		cout<<"Graphs are not Cyclic\n";
// }

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	dsuf.resize(V+10,-1);	//Mark all vertices as separate subsets with only 1 element
	//vector<pair<int,int>> edge_List;	//Adjacency list
	for(int i=0;i<E;++i)
	{
		int node1, node2;
		cin>>node1>>node2;
		union_op(node1, node2);
		//edge_List.push_back({node1, node2});

	}
	while(1){
	int searchRoot;
	cout << "Enter search node: ";
	cin >> searchRoot;
	cout << "Root node of " << searchRoot << " = " << findRoot(searchRoot) << endl;
	
	int node1, node2;
	cout << "Check connection node1: ";
	cin >> node1;
	cout << "Check connection node2: ";
	cin >> node2;
	check_Connection(node1, node2);
	}
	//checkCycle(edge_List);
	
	
	return 0;
}