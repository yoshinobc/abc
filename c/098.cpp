#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,min,N;
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  
  char str[N];
  for(int i = 0;i < N;++i){
    cin >> str[i];
  }


  int f[N],b[N];
  for(int i = 0;i < N;i++){
    f[i] = 0;
    b[i] = 0;
  }
  scanf(" %c", &str[N]);

  for(int i = 1;i < N;i++){
    if(str[i] == 'E'){
      b[0]++;
    }
  }

  for(int i = 1;i < N;i++){
    if(str[(i-1)] == 'W'){
      f[i] = f[i-1] + 1;
    }
    else{
      f[i] = f[i-1];
    }
    
    if(str[i] == 'E'){
      b[i] = b[i-1] - 1;
    }
    else{
      b[i] = b[i-1];
    }
  }
  min = 100000000;
  for(int i = 0;i < N;i++){
    if(min > f[i] + b[i]){
      min = f[i] + b[i];
    }
  }
  cout << min << "\n";
  return 0;
}


