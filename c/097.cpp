#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string str;
  cin >> str;
  
  int i,j,k;
  cin >> k;

  std::vector<string> S;
  for(int i = 0;i <= str.size();i++){
    for(int j = 1;j <= str.size();j++){
      if (j <= k){
      S.push_back(str.substr(i,j));
      }
      else {
        break;
      }
    }
  }
  sort(S.begin(),S.end());
  S.erase(unique(S.begin(),S.end()),S.end());
  cout << S[k] <<endl;
  return 0;
}

