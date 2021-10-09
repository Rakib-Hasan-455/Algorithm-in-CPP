#include<bits/stdc++.h>

using namespace std;
#define Mx 50

vector<pair<int,int> >graph[Mx];
int dis[Mx],vis[Mx],par[Mx];

int T = 0;


priority_queue<pair<int,int> >PQ;

void Prims(int src)
{
    /// set all cost to infinity

    for(int i=0;i<10;i++)dis[i] = 10000;

    int Mst = 0;
    dis[src] = 0;
    par[src] = src;

    PQ.push(make_pair(0,src) );


    while(!PQ.empty())
    {
        pair<int,int> p = PQ.top();
        PQ.pop();

        /// a ke jodi u boli, v kara?
        /// v----> c, f, e
        int u = p.second;
        if(vis[u])continue;
        vis[u] = 1;
        Mst = Mst + dis[u];
        cout<<u<<" "<<dis[u]<<" "<<Mst<<endl;

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i].first;

            if(dis[v] >  graph[u][i].second)
            {
                dis[v] =  graph[u][i].second;
                par[v] = u;
                /// As priority queue is max heap, se we put negative value.
                PQ.push( make_pair(-dis[v], v) );
            }
        }

    }


    cout<<"Final Result is : "<<Mst<<endl;
}


int main()
{
   // freopen("prims.txt","r",stdin);
//    freopen("output_dijkstra.txt","w",stdout);

    int node, edge=0;
    int a,b,c;
    /// Input Node and Edge



    cin>>node>>edge;

    /// For each edge input edge details such edge there is an edge between a to b

    for(int i=1;i<=edge;i++)
    {
        cin>>a>>b>>c;
        pair<int,int> p = make_pair(b,c);

        graph[a].push_back(p);

        p = make_pair(a,c);
        graph[b].push_back(p);
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
            if(j)cout<<",";
            cout<<"("<<graph[i][j].first<<","<<graph[i][j].second<<")";
        }
        cout<<endl;

    }

    Prims(1);
    /// Input Test Passed
    /// Call BFS for a node, here we are calling it for node number = 2;

    /// Finally see the result

//    for(int i=1;i<=node;i++)
//    {
//        cout<<i<<": Distance from 5"<<" to "<<i<<" "<<dis[i]<<endl;
//    }

//    for(int i=1;i<=node;i++)
//    {
//        cout<<"Node#="<< char('a' + i-1)<<", Parent = "<< char('a' + par[i]-1) <<" and dis "<<dis[i]<<endl;
//    }
//
//
//    for(int i=1;i<=node;i++)
//    {
////        printPar(i);
//    }

}


/*

9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7




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

