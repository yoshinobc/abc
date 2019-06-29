#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<int> back_number;

void dfs(int i,vector<vector<int> >& graph){
  visited[i] = 1;
  for(int k=0;k<graph[0].size();k++){
    if(!visited[k] && graph[i][k]) dfs(k,graph);
  }
  back_number.push_back(i);
}

void rdfs(int i,vector<vector<int> >& graph){
  //cout << i << " " << graph[0].size() << endl;
  visited[i] = 1;
  for(int k=0;k<graph[0].size();k++){
    if(!visited[k] && graph[i][k]) rdfs(k,graph);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  while(1){
  int n,m;
  cin >> n >> m;
  if(n==0 && m==0) break;
  vector<vector<int> > graph(n,vector<int>(n));
  vector<vector<int> > graph_mirror(n,vector<int>(n));
  back_number.clear();
  visited.clear();
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) graph[i][j] = 0;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    if(c == 1) {
      graph[a-1][b-1] = 1;
      graph_mirror[b-1][a-1] = 1;
    }
    else{
      graph[a-1][b-1] = 1;
      graph[b-1][a-1] = 1;
      graph_mirror[a-1][b-1] = 1;
      graph_mirror[b-1][a-1] = 1;
    }
  }
  visited.resize(n);
  for(int i=0;i<n;i++) visited[i] = 0;
  bool flag2 = true;
  for(int i=0;i<n;i++){
    back_number.clear();
    for(int k=0;k<n;k++) visited[k] = 0;
    dfs(i,graph);
    if (back_number.size() == n){
      //cout << i;
      break;
    }
    if(i == n-1) flag2 = false;
  }
  if (flag2){
  //for(int i=0;i<n;i++) cout << back_number[i];
  //cout << endl;

  for(int i=0;i<n;i++) visited[i] = 0;
  /*
  cout << back_number[n-1] << endl;

  cout << "mirror" << endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << graph_mirror[i][j];
    }
    cout << endl;
  }

  cout << "graph" << endl;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << graph[i][j];
    }
    cout << endl;
  }
  */
  rdfs(back_number[n-1],graph_mirror);
  //for(int i=0;i<n;i++) cout << visited[i];
  //cout << endl;
}
  bool flag = true;
  for(int i=0;i<n;i++){
    if(!visited[i]) flag = false;
  }
  if(flag && flag2) cout << 1 << endl;
  else cout << 0 << endl;
}
  return 0;
}
