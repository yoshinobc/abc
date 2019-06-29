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
  int n;
  cin >> n;
  int ans[n];
  vector<vector<int> > v(n,vector<int>(3));
  for(int i=0;i<n;i++){
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }
  for(int i=0;i<n;i++){
    sort(v[i].begin(),v[i].end());
    cout << "Case " << i+1 << ": " << v[i][1] << endl;
  }
  return 0;
}
