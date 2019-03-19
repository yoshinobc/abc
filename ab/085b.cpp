#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int d[n];
  for(int i=0;i<n;i++) cin >> d[i];
  sort(d,d+n);
  int count = 1;
  for(int i=0;i<n-1;i++){
    if(d[i] < d[i+1]) count++;
  }
  cout << count << endl;
  return 0;
}
