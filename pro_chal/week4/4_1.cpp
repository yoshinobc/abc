#include <bits/stdc++.h>
using namespace std;
typedef stack<int> st;

vector<int> visited;
void dfs(int i,int j,vector<vector<int> >& graph){
  if (i == j) return ;
  visited[i] = 1;
  for(int k=0;k<visited.size();k++){
      if(graph[i][k] && !visited[k]) dfs(k,j,graph);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  int cases;
  cin >> cases;
  for(int c=0;c<cases;c++){
    int l;
    cin >> l;
    vector<vector<int> > graph(l,vector<int>(l));
    for (int i=0;i<l;i++){
      for (int j=0;j<l;j++){
        int a;
        cin >> a;
        graph[i][j] = a;
      }
    }
    bool ans[l][l];
    visited.resize(l);
    for(int k=0;k<l;k++) visited[k] = 0;
    dfs(0,-1,graph);
    for(int i=0;i<l;i++) cout << visited[i];
    vector<int> visited_cp(l);
    for(int k=0;k<l;k++) visited_cp[k] = visited[k];
    for(int i=0;i<l;i++){
      for(int k=0;k<l;k++) visited[k] = 0;
      dfs(0,i,graph);
      for(int j=0;j<l;j++){
        if(visited_cp[j] && !visited[j]) ans[i][j] = 1;
        else ans[i][j] = 0;
      }
      ans[i][i] = visited_cp[i];
    }
    cout << "Case " << c+1 << ":" << endl;
    cout << "+";
    for (int i=-l+1;i<l;i++){
      cout << "-";
    }
    cout << "+" << endl;
    for(int i=0;i<l;i++){
      cout << "|";
      for(int j=0;j<l;j++){
        if (ans[i][j]) cout << "Y";
        else cout << "N";
        cout << "|";
      }
      cout << endl;
      cout << "+";
      for (int i=-l+1;i<l;i++){
        cout << "-";
      }
      cout << "+" << endl;
    }
  }
  return 0;
}
