#include <bits/stdc++.h>
using namespace std;
#define SIZE(buff) (sizeof(buff)/sizeof(buff[0]))
#define _DIVUP(vWarareru, vWaru)        ( !(vWaru) ? 0u : _UNSAFE_DIVUP( vWarareru, vWaru ) )
#define _UNSAFE_DIVUP(vWarareru, vWaru) ( ( (vWarareru) + ( (vWaru) - 1u) ) / (vWaru) )

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
  int n,k;
  cin >> n >> k;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  int *mn = min_element(a,a+SIZE(a));
  int min_index = mn - a;
  int ans = 999999999;
  for (int i=-1;i<=1;i++){
    int _ans = _DIVUP(min_index+i,k) + _DIVUP(n-min_index+i,k);
    if (ans >= _ans) ans = _ans;
  }
  cout << ans << endl;
  return 0;
}
