#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a+b>c+d) cout << "Left" << endl;
  else if(a+b==c+d) cout << "Balanced" << endl;
  else cout << "Right" << endl;
  return 0;
}
