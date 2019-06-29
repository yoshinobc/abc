#include <bits/stdc++.h>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  int cases;
  cin >> cases;
  for (int c=0;c<cases;c++)
  {
    int obtain;
    cin >> obtain;
    int num;
    cin >> num;
    vector<int> bar(num);
    bool dp[num+1][obtain+1];
    for(int i=0;i<=num;i++) for(int j=0;j<=obtain;j++) dp[i][j] = false;
    dp[0][0] = true;
    for(int i=0;i<num;i++)
    {
      int len;
      cin >> len;
      bar[i] = len;
    }
    for(int i=0;i<num;i++)
    {
      for(int j=0;j<=obtain;j++)
      {
        dp[i+1][j] |= dp[i][j];
        if (j >= bar[i]) dp[i+1][j] |= dp[i][j-bar[i]];
      }
    }
    if(dp[num][obtain]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
