#include <bits/stdc++.h>
using namespace std;
pair<int, int> job;
vector<pair<int,int> > jobs;

bool pairCompare(pair<int,int> firstElof, pair<int,int> secondElof){
  return firstElof.second < secondElof.second;
}


unsigned long long int gdb(unsigned long long int a,unsigned long long int b){
  unsigned long long int x = a * b;

if(a<b){
  unsigned long long int tmp = a;
  a = b;
  b = tmp;
}

unsigned long long int r = a % b;
while(r!=0){
  a = b;
  b = r;
  r = a % b;
}
return x/b;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  unsigned long long int n,k;
  string str;
  cin >> n;
  vector<int> xvec;
  vector<int> yvec;
  vector<vector<int> > graph(100000,vector<int>(100000+1));
  int x_min,y_min,x_max,y_max;
  x_min = y_min = 2000000;
  x_max = y_max = -1;
  for(int i=0;i<100000;i++) for(int j=0;j<100000;j++) graph[i][j] = 0;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1] = 1;
    if (x_min > a) x_min = a;
    if (y_min > b) y_min = b;
    if (x_max < a) x_max = a;
    if (y_max < b) y_max = b;
    xvec.push_back(a-1);
    yvec.push_back(b-1);
  }
  for(int i=0;i<xvec.size();i++){
    xvec[i].size()
  }


  return 0;
}
