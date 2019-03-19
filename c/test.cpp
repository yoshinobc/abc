#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
  int n,m,b,k;
  cin >> n >> m;
  int a[m];
  int count = 0;
  for(int i=0;i<m;i++) a[i] = 0;
  for(int i=0;i<n;i++){
    cin >> k;
    for(int j=0;j<k;j++){
      cin >> b;
      a[b]++;
    }
  }
  for(int i=0;i<m;i++){
    if(a[i] == n) count++;
  }
  cout << count << endl;
  return 0;
}
*/
/*
int main()
{
  int y,m,d;
  cin >> y;
  cin.ignore();
  cin >> m;
  cin.ignore();
  cin >> d;
  if (y < 2019) cout << "Heisei" << endl;
  else if (y == 2019) {
    if (m < 4) cout << "Heisei" << endl;
    else if(m == 4) {
      if (d <= 30) cout << "Heisei" << endl;
    }
    else cout << "TBD" << endl;
  }
  else cout << "TBD" << endl;

  return 0;
}
*/
/*
int main()
{
  int n;
  cin >> n;
  double y = 0;
  double b = 0;
  double num = 0;
  string std;
  for (int i=0;i < n;i++){
    cin >> num;
    cin >> std;
    if (std == "JPY") y+=num;
    else b+=num;
  }
  cout << y + b*380000 << endl;
  return 0;
}
*/
/*
int main()
{
  int a,b,c;
  cin >> a >> b >> c;
  int count = 0;
  while(b>=a){
    if (c <= count) break;
    count++;
    b -= a;
  }
  cout << count << endl;
  return 0;
}
*/
int main()
{
  int a,b,k;
  int big;
  vector <int> ans;
  int count;
  cin >> a >> b >> k;
  if (a > b) big = a;
  else big = b;
  for(int i=1;i<=big;i++){
    if ((a%i==0) && (b%i==0)) ans.push_back(i);
  }
  if (ans.size() == 0) cout << 0 << endl;
  else cout << ans[ans.size()-k] << endl;
  return 0;
}
