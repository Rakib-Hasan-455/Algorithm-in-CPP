#include<bits/stdc++.h>

using namespace std;

vector<int>graph[15];
int start[15];
int finish[15];

int T = 0;

void DFS(int u)
{
    ++T;
    start[u] = T;

    for(int i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i];
        if(start[v]==0)
        {
            DFS(v);
        }
    }

    ++T;
    finish[u] = T;

}



int main()
{
//    freopen("input_dfs.txt","r",stdin);
//    freopen("output_dfs.txt","w",stdout);

    int node, edge;
    int a,b;
    /// Input Node and Edge
    cin>>node>>edge;

    /// For each edge input edge details such edge there is an edge between a to b

    for(int i=1;i<=edge;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);

    }

    /// Test whether we took the input correctly

    for(int i=1;i<=node;i++)
    {
        /// Ith node r adjacency List ase graph[i]
        ///
        int m = graph[i].size();
        cout<<"Adjacency List of Node "<<i<<": ";
        for(int j=0;j<m;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;

    }
    /// Input Test Passed
    /// Call BFS for a node, here we are calling it for node number = 2;

    for(int i=1;i<=node;i++)
    {
        /// jodi node ta visited na thake tobe DFS perform korte hobe
        /// if logic
        if(finish[i]==0) DFS(i);
    }



    vector<pair<int,int> >dag;

    for(int i=1;i<=node;i++)
    {
        dag.push_back(make_pair(finish[i],i ) );
    }

    //sort(dag.begin(),dag.end());
    reverse(dag.begin(),dag.end());

    for(int i=0;i<dag.size();i++)
    {
        cout<<dag[i].second<<" ***** "<<dag[i].first<<endl;
    }



//    DFS(1);

    /// Finally see the result

    for(int i=1;i<=node;i++)
    {
        cout<<"For "<<i<<"th node Start Time = "<<start[i]<<" and Finish Time = "<<finish[i]<<endl;
    }


}


/*
 9 9
 2 3
 2 4
 3 4
 3 6
 1 4
 5 6
 5 7
 7 8
 6 8

9 9
 b c
 b d
 c d
 c f
 a d
 e f
 e g
 g h
 f h




8 14
1 2
1 4
1 5
2 3
2 4
3 1
4 3
5 4
5 6
6 4
7 5
7 6
7 8
8 4




*/

