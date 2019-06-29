#include <bits/stdc++.h>
using namespace std;

string rec(double n, double m,double x_l,double y_l,double x_c,double y_c,double x_r,double y_r)
{
  if (n/m == x_c/y_c) return "";
  else if(n/m < x_c/y_c) return "L" + rec(n,m,x_l,y_l,(x_l+x_c),(y_l+y_c),x_c,y_c);
  else return "R" + rec(n,m,x_c,y_c,(x_c+x_r),(y_c+y_r),x_r,y_r);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  while(1)
  {
    double n,m;
    cin >> n >> m;
    n = (double)n;
    m = (double)m;
    if (n==1 && m==1) break;
    string str = rec(n,m,0.0,1.0,1.0,1.0,1.0,0.0);
    cout << str << endl;
  }
  return 0;
}
