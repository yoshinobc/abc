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
  int n,a,b;
  int ans = 0;
  string num;
  cin >> n >> a >> b;
  for(int i=1;i<=n;i++){
    num = to_string(i);
    int sum = 0;
    for(int j=0;j<num.size();j++) sum += ctoi(num[j]);
    if (a <= sum && sum <= b) ans += i;
  }
  cout << ans << endl;
  return 0;
}
