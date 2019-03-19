#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  bool ok = true;
  if (s.size() != a+b+1) ok = false;
  if (s[a] != '-') ok = false;
  for(int i=0;i < s.size();i++){
    if (((s[i] < 48) || (57 < s[i])) && i != a) ok = false;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
