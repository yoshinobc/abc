#include <bits/stdc++.h>
using namespace std;

int table[10][100];
int dis[10][100];
int path[10][100];

int sel(int a,int b){
  if(a < b) return 1;
  else if(a == b) return 0;
  else return -1;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  memset(table,0,sizeof(table));
  memset(dis,0,sizeof(dis));
  memset(path,0,sizeof(path));
  while(1){
  int m=0;
  int n=0;
  cin >> m >> n;
  if(m == 0 && n == 0) break;
  for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
    int a;
    cin >> a;
    table[i][j] = a;
    dis[i][j] = 99999999;
  }
  for(int i=0;i<m;i++) dis[i][n-1] = table[i][n-1];
  for(int i=n-2;i>=0;i--){
    for(int j=0;j<m;j++){
      int t1,t2,t3;
      int min_num = 999999;
      int num;
      t1 = (j + m - 1) % m;
      t2 = j;
      t3 = (j + 1) % m;
      num = sel(dis[t1][i+1],dis[t2][i+1]);
      if(num == 1) min_num = t1;
      else if(num == -1) min_num = t2;
      else{
        if(t1 < t2) min_num = t1;
        else min_num = t2;
      }
      num = sel(dis[min_num][i+1],dis[t3][i+1]);
      if(num == -1) min_num = t3;
      else if(num == 0) {
        if(min_num > t3) min_num = t3;
      }
      dis[j][i] = dis[min_num][i+1] + table[j][i];
      path[j][i] = min_num;
    }
  }
  int x = 99999;
  int min_num = 99999;
  for(int i=0;i<m;i++){
    if(dis[i][0] < min_num){
      min_num = dis[i][0];
      x = i;
    }
  }
  for(int i=0;i<n-1;i++){
    cout << x+1 << " ";
    x = path[x][i];
  }
  cout << x+1 << endl;
  cout << min_num << endl;
}
}
