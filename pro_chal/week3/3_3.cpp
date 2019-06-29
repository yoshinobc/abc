#include <bits/stdc++.h>
using namespace std;

int table[30][30];
int max_h[30];
int n;

/*
int solve(int x,int y){
  int sum_a;
  for(int i=1;i<=x;i++){
    for(int j=1;j<=y;j++){
      //cout << i << " " << j << ":" << table[i][j] << endl;
      if(table[x][y]-table[i-1][y]-table[x][j-1]+table[i-1][j-1]==(x-i+1)*(y-j+1)) sum_a=max(sum_a, (x-i+1)*(y-j+1));
    }
  }
  //cout << x << y << endl;
  return sum_a;
}
*/
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  int cases;
  cin >> cases;
  string test;
  getline(cin,test);
  for(int c=0;c<cases;c++){
    memset(table,0,sizeof(table));
    //memset(max_h,0,sizeof(max_h));
    int i=0;
    n=0;
    int max_a = 0;
    int l=0;
    int w=0;
    int a = 0;
    getline(cin,test);
    while(1){
      string s;
      getline(cin,s);
      //cout << s << endl;
      n = s.size();
      //int sum_n = 0;
      for(int j=0;j<n-1;j++){
        //cout << "i:" << i << "j:" << j << endl;
        if (s[j] == '0') {
          table[i][j] = 0;
        }
        else {
          table[i][j] = 1;
        }
      }
      i++;
      if(i == n-1) break;
    }
    /*
    for(int i=0;i<30;i++){
      for(int j=0;j<30;j++){
        cout << table[i][j];
      }
      cout << endl;
    }
    */
    for(int i=0;i<n;i++){
      memset(max_h,0,sizeof(max_h));
      for(int j=i;j<n;j++){
        for(int k=0;k<n;k++){
          max_h[k] += table[j][k];
          if(k ==0 || a != (l * w)) {
            a = 0;
            l = 0;
          }
          l++;
          w = j-i+1;
          a += max_h[k];
          if(a == l*w){
            if(max_a < a) max_a = a;
          }
        }
      }
    }
    //cout << "test";
    /*
    for(int i=0;i<30;i++){
      for(int j=0;j<30;j++){
        cout << table[i][j];
      }
      cout << endl;
    }
    */
    //cout << n << endl;
    /*
    for(int x=0;x<=n;x++){
      for(int y=0;y<=n;y++){
        //int a = solve(i,j);
        //cout << i << j << a << endl;
        for(int i=1;i<=x;i++){
          for(int j=1;j<=y;j++){
            //cout << x << y << i << j << endl;
            //cout << i << " " << j << ":" << table[i][j] << endl;
            if(table[x][y]-table[i-1][y]-table[x][j-1]+table[i-1][j-1]==(x-i+1)*(y-j+1)) {
              max_a=max(max_a, (x-i+1)*(y-j+1));
              //cout << max_a << endl;
            }
          }
        }
      }
    }
    */
    cout << max_a << endl;
    cout << endl;
  }
  return 0;
}
