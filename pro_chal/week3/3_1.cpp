#include <bits/stdc++.h>
using namespace std;

int dp[201][21];
int k_g[21][21];
int min_v = -1000000;
int k_l;
int money;

int solve(int m,int k)
{
    if(m < 0) return min_v;
    else if(k == k_l) return dp[m][k] = money - m;
    else if(dp[m][k] != -1) return dp[m][k];
    else{
      int ans = min_v;
      for(int i=1;i <= k_g[k][0];i++) ans = max(ans,solve(m - k_g[k][i],k+1));
      return dp[m][k] = ans;
    }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  int cases;
  cin >> cases;
  for(int c=0;c<cases;c++){
    cin >> money >> k_l;
    memset(k_g,0,sizeof(k_g));
    memset(dp,-1,sizeof(dp));
    //cout << "money" << money << "k_l" << k_l << endl;
    for(int i=0;i<k_l;i++){
      int l;
      cin >> l;
      k_g[i][0] = l;
      //cout << "l" << l << endl;
      for(int j=1;j<=l;j++){
        int b;
        cin >> b;
        k_g[i][j] = b;
      }
    }
    //for(int i=0;i<21;i++) {
    //  for(int j=0;j<21;j++) cout << k_g[i][j] << " ";
    //  cout << endl;
    //}
    int ans = solve(money,0);
    if(ans != min_v) cout << ans << endl;
    else cout << "no solution" << endl;
  }
  return 0;
}
