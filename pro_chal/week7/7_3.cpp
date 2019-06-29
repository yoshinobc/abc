#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long int> v(1000000);

unsigned long long int nibu(unsigned long long int x,unsigned long long int l,unsigned long long int r){
  while(l <= r){
    unsigned long long int mid = (l+r)/2;
    if(v[mid] >= x) r = mid -1;
    else l = mid + 1;
  }
  return l;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  vector<unsigned long long int> v_(1000000);
  v[0] = 0;
  v[1] = 1;
  v[2] = 3;
  unsigned long long int i;
  for(i=3;i<1000000;i++){
    v[i] = v[i-1] + nibu(i,1,i-1);
  }
  unsigned long long int a;
  while(1){
    cin >> a;
    if(a == 0) break;
    cout << nibu(a,1,i) << endl;
  }
  return 0;
}
