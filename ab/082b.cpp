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
  string s,t;
  cin >> s;
  cin >> t;
  bool ok = false;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end(),greater<int>());
  for(int i=0;i<s.size();i++){
    if (s[i] < t[i]){
      ok = true;
      break;
    }
    else if(s[i] > t[i]){
      break;
    }
    if(i == s.size()-1 && s.size() < t.size()) ok = true;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
