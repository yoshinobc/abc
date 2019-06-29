#include <bits/stdc++.h>
using namespace std;

int table[1001];
int s_p[1001];
int n;
struct data{
    int weight, value, id;
};
bool cmp(data a,data b){
   return a.value > b.value;
 }
vector<data> v;
int solve(int x){
  int num = table[x];
  if(num != -1) return num;
  int max_i=0;
  for(int i=x+1;i<n;i++){
    if(v[x].weight < v[i].weight){
      int k = solve(i);
      if(k > max_i){
        max_i = solve(i);
        s_p[x] = i;
      }
    }
  }
  table[x] = 1 + max_i;
  return table[x];
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  int ans = -1;
  memset(table,-1,sizeof(table));
  memset(s_p,-1,sizeof(s_p));
  while(1){
  int a=-1;
  int b=-1;
  cin >> a >> b;
  if(a == -1 && b == -1) break;
  data d;
  d.weight = a;
  d.value = b;
  d.id = n+1;
  v.push_back(d);
  n++;
}
sort(v.begin(),v.end(),cmp);
int s;
for(int i=0;i<n;i++){
  if(ans < solve(i)){
    ans = solve(i);
    s = i;
  }
}
while(1){
  if(s == -1) break;
  cout << v[s].id << endl;
  s = s_p[s];
}
}
