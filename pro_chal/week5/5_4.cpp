#include <bits/stdc++.h>
using namespace std;
#define INF 9999999

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  int count = 1;
  while(1){
    int n,m;
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    vector<vector<int> > graph(n,vector<int>(n));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j) graph[i][j] = 1;
        else graph[i][j] = 0;
      }
    }
    map<string,int> hmap;
    map<string,int>::iterator it;
    int num = 0;
    int x,y;
    for(int i=0;i<m;i++){
      string a,b;
      cin >> a >> b;
      it = hmap.find(a);
      if(it == hmap.end()) {
        hmap[a] = num;
        x = num;
        num++;
      }
      else x = it->second;
      it = hmap.find(b);
      if(it == hmap.end()){
        hmap[b] = num;
        y = num;
        num++;
      }
      else y = it->second;
      //cout << x << " " << y << endl;
      graph[x][y] = graph[y][x] = 1;
    }
    /*
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << graph[i][j];
      }
      cout << endl;
    }
    */
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          int a = graph[i][j];
          int b = graph[i][k];
          int c = graph[k][j];
          if(a==0) a = INF;
          if(b==0) b = INF;
          if(c==0) c = INF;
          graph[i][j] = min(a,b+c);
        }
      }
    }
    int min_num = -1;
    bool flag = true;
    /*
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << graph[i][j];
      }
      cout << endl;
    }
    */
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(graph[i][j] >= INF){
          flag = false;
          break;
        }
        if(min_num<graph[i][j]) min_num = graph[i][j];
      }
    }
    cout << "Network " << count << ": ";
    if(flag) cout << min_num << endl;
    else cout << "DISCONNECTED" << endl;
    cout << endl;
    count++;
  }
  return 0;
}
