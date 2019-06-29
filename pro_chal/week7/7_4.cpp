#include <bits/stdc++.h>
using namespace std;

int main(){
  //cin.tie(0);
  //ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  unsigned long long int a;
  while(cin>>a){
    //cin >> a;
    //cout << "a:" << a << endl;
    if(a < 3) break;
    if(a%2 != 0) {
      a /= 2;
      //cout << "kisuu:" << a << endl;
      cout << a*(a-1)*(2*a-1)/3+a*(a-1)/2 << endl;
    }
    else{
      a /= 2;
      a--;
      //cout << "guusuu;" << a << endl;
      cout << a + a*(a-1)*(2*a-1)/3 + 3*a*(a-1)/2 << endl;
    }
    //cout << v[a] << endl;
  }
  return 0;
}
