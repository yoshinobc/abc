#include <bits/stdc++.h>
using namespace std;

vector<char> lines;
vector<vector<char> > graph;
map<char,bool> visited;

string matlix[101];
bool is_m(int i,int e,int j){
  for(i;i<=e;i++) if(matlix[i][j] != '1') return false;
  return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    int cases;
    cin >> cases;
    //getline(cin,test);
    for(int c=0;c<cases;c++){
      //getline(cin,test);
      //getline(cin,line);
      //cout << line << endl;
      cin >> matlix[0];
      int a;
      int ans=0;
      //matlix[0] = line;
      for(int i=1;i<matlix[0].size();i++) {
        //getline(cin,line);
        //cout << line << endl;
        cin >> matlix[i];
      }
      //for(int i=0;i<matlix[0].size();i++) cout << matlix[i] << endl;
      for(int k = 1;k <= matlix[0].size();k++){
        for(int i=0;i+k-1<matlix[0].size();i++){
          a = 0;
          for(int j=0;j<matlix[0].size();j++){
            if(is_m(i,i+k-1,j)) {
              a += k;
              //cout << a << " " << k << " " << i << " " << j << endl;
            }
            else a = 0;
            if(a > ans) {
              ans = a;
              //cout << ans << endl;
            }
          }
        }
      }
      cout << ans << endl;
      if(c < cases-1) cout << endl;
    }
    return 0;
  }
