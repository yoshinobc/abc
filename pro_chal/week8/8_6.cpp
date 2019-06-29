#include <bits/stdc++.h>
using namespace std;

#define Pi acos(-1)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  while(true){
    int a,b,c,d;
    a=b=c=-1;
    cin >> a >> b >> c >> d;
    if(a==-1) break;
    double ans;
    ans = a*tan(d*Pi/180.0);
    if(ans<=c) ans = a*b*(c-ans/2);
    else ans =b*c*c*tan(Pi/2-d*Pi/180.0)/2;
    cout << fixed;
    cout << setprecision(3) << ans << " mL" << endl;
  }
  return 0;
}
