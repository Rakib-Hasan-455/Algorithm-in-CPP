#include <bits/stdc++.h>
using namespace std;


vector< int > edges[1000];
vector< int > costs[1000];

int main(){
 

  int N,E,i;
  cin >> N >> E;
 

  for(i=0;i<E;i++){
    int x,y;

    cin >> x >> y; 
    x--;
    y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  } 
 
  queue <int> Q; int level[N];

  for(i=0;i<N;i++){
    level[i] = -1;
  }
  int s, d;
  cin >> s >> d;
  s--;
  d--;
  Q.push( s );
  level[s] = 0;

  int u,v,edgeSize;
    cout << "BFS Traversal result => ";
    cout << s+1 << " ";
  while( ! Q.empty() ){
    u = Q.front();
    Q.pop();

    edgeSize = edges[u].size();
    for( i=0 ; i < edgeSize; i++){
        v = edges[u][i];
        if(level[v] == -1){
            cout << v+1 << " ";
            Q.push( v );
            level[v] = level[u] + 1;
        }
    }  
  }  


  cout << "\nDistance:" <<level[d] <<" ";

  return 0;
}