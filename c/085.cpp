#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,y;

  cin >> n >> y;
  bool tf = 0;
  for(int i = 0;i <= n;i++){
    for(int j = 0;j <= n;j++){
      if(10000*i+5000*j+1000*(n-i-j) == y && (n-i-j) >= 0){
        cout << i << " " << j << " " << (n-i-j) << endl;
        tf = 1;
        n = -1;
      }
    }
  }

  if(!tf){
    cout << -1 << " " << -1 << " " << -1 << endl;
  }
  return 0;
}
