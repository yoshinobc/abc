#include <bits/stdc++.h>
using namespace std;

int dist[2001];

struct Edge{
  int start;
  int end;
  int cost;
};

bool bellman_ford(struct Edge* edges,int E,int V){
  for(int count=0;count<V;count++){
    bool update = false;
    for(int i=0;i<E;i++){
      int s = edges[i].start;
      int e = edges[i].end;
      int c = edges[i].cost;
      if(dist[s] + c < dist[e]){
        dist[e] = dist[s] + c;
        update = true;
      }
    }
    if(!update) return true;
  }
  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  int cases;
  cin >> cases;
  //cout << "test";
  for(int c=0;c<cases;c++){
    //cout << c << endl;
    int V,E;
    cin >> V >> E;
    bool flag = false;
    //cout << "test";
    struct Edge edges[E];
    //cout << "test1";
    for(int i=0;i<E;i++) cin >> edges[i].start >> edges[i].end >> edges[i].cost;
    //cout << "test2";
    memset(dist,0,sizeof(dist));
    flag = bellman_ford(edges,E,V);
    if(flag) cout << "not possible" << endl;
    else cout << "possible" << endl;
  }
  return 0;
}
