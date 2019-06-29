#include <bits/stdc++.h>
using namespace std;
#define INF 9999999

/*
struct Edge{
  int end;
  int cost;
};

typedef pair<int,int> P;
vector<Edge> G[101];
vector<int> d;
int V;

void dijkstra(int s,int bh,int of){
  d.assign(V,INF);

  for(int i=0;i<V;i++) cout << d[i];
  cout << endl;

  if(s == bh || s == of) d[s] = INF;
  else d[s] = 0;
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0,s));
  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second;
    //cout << v << endl;
    if(d[v] < p.first) continue;
    for(int i=0;i<G[v].size();i++){
      Edge e = G[v][i];
      if (d[e.end] > d[v] + e.cost){
        d[e.end] = d[v] + e.cost;
        que.push(P(d[e.end],e.end));
      }
    }
  }
}
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  while(1){
    int p,r,bh,of,yh,m;
    p = 0;
    cin >> p >> r >> bh >> of >> yh >> m;
    bh = bh-1;
    of = of-1;
    yh = yh-1;
    m = m-1;
    int graph_b[p][p];
    int graph_s[p][p];
    for(int i=0;i<p;i++){
      for(int j=0;j<p;j++){
        if(i==j) graph_b[i][j] = graph_s[i][j] = 0;
        else graph_s[i][j] = graph_b[i][j] = INF;
      }
    }
    //cout << "test3" << endl;
    for(int i=0;i<r;i++){
      int s,e,c;
      cin >> s >> e >> c;
      s-=1;
      e-=1;
      //cout << s <<" "<< e << " "<< c << endl;
      graph_b[s][e] = graph_b[e][s] = graph_s[s][e] = graph_s[e][s] = c;
    }
    if(p==0) break;
    /*
    for(int i=0;i<p;i++) {
      Edge edge;
      edge.end = i;
      edge.cost = INF;
      G[i].push_back(edge);
    }
    */
    /*
    V = p;
    for(int i=0;i<r;i++){
      int s,e,c;
      cin >> s >> e >> c;
      Edge edge;
      s-=1;
      e-=1;
      edge.end = e;
      edge.cost = c;
      if(e == bh || e == of) {
        edge.cost = INF;
        G[s].push_back(edge);
      }
      else G[s].push_back(edge);
    }
    */
    /*
    for(int i=0;i<p;i++){
      Edge edge;
      edge.end = i;
      edge.cost = 0;
      if(i == bh || i == of) edge.cost = INF;
      G[i].push_back(edge);
    }
    */
    //cout << "test" << endl;
    vector<bool> closed;
    closed.assign(p,false);
    for(int i=0;i<p;i++){
      for(int j=0;j<p;j++){
        for(int k=0;k<p;k++){
          graph_b[j][k] = min(graph_b[j][k],graph_b[j][i]+graph_b[i][k]);
        }
      }
    }
    //cout << "test2" << endl;
    for(int i=0;i<p;i++) if(graph_b[bh][of] == graph_b[bh][i] + graph_b[i][of]) closed[i] = true;
    /*
    for(int i=0;i<p;i++){
      for(int j=0;j<G[i].size();j++){
        cout << "s: " << i << " e: " << G[i][j].end << " c: " << G[i][j].cost << endl;
      }
    }
    */
    //dijkstra(yh,bh,of);
    //cout << "test" << endl;
    for(int i=0;i<p;i++){
      if (closed[i]) continue;
      for(int j=0;j<p;j++){
        if(closed[j]) continue;
        for(int k=0;k<p;k++){
          if(closed[k]) continue;
          graph_s[j][k] = min(graph_s[j][k],graph_s[j][i]+graph_s[i][k]);
        }
      }
    }
    int ans = graph_s[yh][m];
    if(ans == INF || closed[yh] || closed[m]) cout << "MISSION IMPOSSIBLE." << endl;
    else cout << ans << endl;
    /*
    for(int i=0;i<p;i++) cout << d[i];
    cout << endl;
    */

  }
  return 0;
}
