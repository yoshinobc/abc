#include <bits/stdc++.h>
using namespace std;
#define INF 9999999

vector<int> visited;
vector<int> d;

int V;
vector<vector<int> > graph_s(26,vector<int>(26));
vector<vector<int> > graph_p(26,vector<int>(26));
/*
struct Edge{
  int end;
  int cost;
};
typedef pair<int,int> P;

vector<int> d_s;
vector<int> d_p;

/*
void dijkstra_s(int s,graph){
  priority_queue<P,vector<P>,greater<P> > que;
  fill(d_s,d_s+V,INF);
  d_s[s] = 0;
  que.push(P(0,s));
  while(!que.empty()){
    p = que.top();
    que.pop();
    int v = p.second;
    if(d_s[v] < p.first) continue;
    for(int i=0;i<graph_s[v].size();i++){
      Edge e = graph_s[v][i];
      if(d_s[e.end] > d_s[v] + e.cost){
        d_s[e.end] = d_s[v] + e.cost;
        que.push(P(d_s[e.end],e.end));
      }
    }
  }
}

void dijkstra_p(int s,graph){
  priority_queue<P,vector<P>,greater<P> > que;
  fill(d_p,d_p+V,INF);
  d_p[s] = 0;
  que.push(P(0,s));
  while(!que.empty()){
    p = que.top();
    que.pop();
    int v = p.second;
    if(d_p[v] < p.first) continue;
    for(int i=0;i<graph_p[v].size();i++){
      Edge e = graph_p[v][i];
      if(d_p[e.end] > d_p[v] + e.cost){
        d_p[e.end] = d_p[v] + e.cost;
        que.push(P(d_p[e.end],e.end));
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
    int n;
    cin >> n;
    if(n == 0) break;
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        if(i==j) graph_s[i][j] = graph_p[i][j] = 0;
        else graph_s[i][j] = graph_p[i][j] = INF;
      }
    }
    V = n;
    for(int i=0;i<n;i++){
      char a,b,c,d;
      int e;
      cin >> a >> b >> c >> d >> e;
      int x = c-'A';
      int y = d-'A';
      if(a == 'M') {
        if(b == 'U') graph_p[x][y] = e;
        else graph_p[x][y] = graph_p[y][x] = e;
      }
      else {
        if(b == 'U') graph_s[x][y] = e;
        else graph_s[x][y] = graph_s[y][x] = e;
      }
    }
    for(int i=0;i<26;i++) graph_p[i][i] = graph_s[i][i] = 0;
    char ss,ps;
    cin >> ss >> ps;
    int ss_i = ss - 'A';
    int ps_i = ps - 'A';
    /*
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        cout << graph_s[i][j];
      }
      cout << endl;
    }
    */
    for(int p=0;p<26;p++){
      for(int q=0;q<26;q++){
        for(int r=0;r<26;r++){
          graph_s[q][r] = min(graph_s[q][r],graph_s[q][p]+graph_s[p][r]);
          graph_p[q][r] = min(graph_p[q][r],graph_p[q][p]+graph_p[p][r]);
        }
      }
    }
    //cout << ss_i << ps_i << endl;
    /*
    for(int i=0;i<26;i++){
      int val = graph_s[ss_i][i]+graph_p[ps_i][i];
      //cout << val << endl;
      cout << i << " " << val << endl;
      if(val < min_n){
        min_n = val;
        ans = i;
      }
    }
    if(min_n == INF) cout << "You will never meet." << endl;
    else cout << min_n << " " << (char)(ans+'A') << endl;
  }
  */
    int min_n = INF;
    int ans;
    vector<int> anses;
    /*
    for(int i=0;i<26;i++) cout << graph_s[ss_i][i];
    cout << endl;
    for(int i=0;i<26;i++) cout << graph_p[ps_i][i];
    cout << endl;
    */
    for(int i=0;i<26;i++){
      int val = graph_s[ss_i][i]+graph_p[ps_i][i];
      if(val == min_n) anses.push_back(i);
      else if(val < min_n){
        min_n = val;
        //cout << min_n << i << endl;
        anses.clear();
        anses.push_back(i);
      }
    }
    //for(int i=0;i<n;i++) cout << anses[i];
    if(min_n == INF) cout << "You will never meet." << endl;
    else {
      cout << min_n;
      for(int k=0;k<anses.size();k++) cout << " " << (char)(anses[k]+'A');
      cout << endl;
    }
  }
  return 0;
}
