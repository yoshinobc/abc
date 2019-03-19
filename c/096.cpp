#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h,w,i,j;
  cin >> h >> w;
  char table[h+2][w+2];
  for(i = 1;i < h+1;i++){
    for(j = 1;j < w+1;j++){
      cin >> table[i][j];
    }
  }
  for(i = 0;i < h+2;i++){
    table[i][0] = '.';
    table[i][w+1] = '.';
  }
  for(j = 0;j < w+2;j++){
    table[0][j] = '.';
    table[h+1][j] = '.';
  }

  string tf = "Yes";
  for(i = 1;i < h+1;i++){
    for(j = 1;j < w+1;j++){
      if(table[i][j] == '#') {
        if(table[i-1][j] == '.' && table[i+1][j] == '.' && table[i][j-1] == '.' && table[i][j+1] == '.') {
          tf = "No";
          break;
        }
      }
    }
  }
  cout << tf << endl;
  return 0;
}



