#include <bits/stdc++.h>
using namespace std;

#define Pi acos(-1)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  while(true){
    int a,b,c;
    a=b=c=-1;
    cin >> a >> b >> c;
    if(a==-1) break;
    double sun,vio,ros;
    double s = (a+b+c)/2.0;
    vio = sqrt(s*(s-a)*(s-b)*(s-c));
    double r = vio*2.0/(a+b+c);
    ros = r*r*Pi;
    double R = a*b*c / 4.0 / vio;
    sun = R*R*Pi - vio;
    vio -= ros;

    cout << fixed;
    cout << setprecision(4) << sun << " ";
    cout << setprecision(4) << vio << " ";
    cout << setprecision(4) << ros << endl;
  }
  return 0;
}
