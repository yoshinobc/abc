#include <bits/stdc++.h>
using namespace std;
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  int i,j;
  int max = 0;
  int i_,j_;
  vector<vector<int> > v;
  int table[1000000];
  for(int i = 0;i < 1000000;i++){
    table[i] = 0;
  }
  while(1)
  {
      if(cin.eof()) break;
      cin >> i_ >> j_;
      v.push_back({i_,j_});
  }
  int ans[v.size()];
  for(int k=0;k<v.size();k++) {
    max = 0;
    i = v[k][0];
    j = v[k][1];
    if (i > j){
      swap(i,j);
    }
    for(int start = i;start<=j;start++){
      int count = 0;
      int num = start;
      if (table[num] != 0){
        count = table[num];
      }
      else{
        while (1) {
          count++;
          if (num==1){
            table[start] = count;
            break;
          }
          if (num%2 != 0){
            num = 3 * num + 1;
          } else{
            num =  num / 2;
          }
        }
      }
      if (count >= max){
        max = count;
      }
    }
    ans[k] = max;
  }
  for(int k=0;k<v.size()-1;k++){
    cout << v[k][0] << " " << v[k][1] << " " << ans[k] << endl;
  }
  return 0;
}
