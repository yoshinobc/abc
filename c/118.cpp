#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
  if (b==0) return a;
  return gcd(b,a%b);
}

int main()
{
  int n;
  int el;
  cin >> n;
  int mo[n];
  for(int i=0;i<n;i++) cin >> mo[i];
  if (n == 1) cout << mo[0] << endl;
  else{
    el = gcd(mo[0],mo[1]);
    if (n ==2) cout << el << endl;
    else{
      for(int i=2;i<n;i++){
        el = gcd(el,mo[i]);
      }
      cout << el << endl;
    }
  }
  return 0;
}
