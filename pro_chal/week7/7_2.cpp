#include <bits/stdc++.h>
using namespace std;

//vector< vector<unsigned int> > table(25,vector<unsigned int>(150) );
unsigned long long int table[25][150];

unsigned long long int count(int dl,int xl){
  if(xl <= dl) return pow(6,dl);
  if(dl == 0) return 0;
  if(table[dl][xl] != -1) return table[dl][xl];
  unsigned long long int sum=0;
  for(int i=0;i<6;i++) {
    sum += count(dl-1,xl-i-1);
  }
  table[dl][xl] = sum;
  return sum;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  memset(table,-1,sizeof(table));
  //for(int i=1;i<=25;i++) table[i][0] = table[i][1] = 1;
  //cout << setprecision(30) << pow(6,14) << endl;
  //cout << setprecision(30) << pow(6,15) << endl;
  for(int i=0;i<=25;i++) {

    table[i][0] = table[i][1] = pow(6,i);
  }
  for(int i=1;i<=25;i++){
    for(int j=1;j<150;j++){
      table[i][j] = count(i,j);
    }
  }
  int n,x;
  while(1){
    cin >> n >> x;
    if(n == 0 && x == 0) break;
    unsigned long long int a = table[n][x];
    unsigned long long int b = pow(6,n);
    unsigned long long int k = __gcd(a,b);
    //cout << a << " " << b << " " << k << endl;
    a /= k;
    b /= k;
    if(a==b) cout << 1 << endl;
    else if(a==0) cout << 0 << endl;
    else cout << table[n][x]/k << "/" << setprecision(30) << pow(6,n)/k << endl;
  }
  return 0;
}
