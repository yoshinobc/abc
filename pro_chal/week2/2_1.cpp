#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  while(1)
  {
    int n,m;
    int ans = 0;
    cin >> n >> m;
    vector<int> dra(n);
    vector<int> sol(m);
    if (n==0 && m == 0) break;

    for(int i=0;i<n;i++)
    {
      int k;
      cin >> k;
      dra[i] = k;
    }
    for(int i=0;i<m;i++)
    {
      int k;
      cin >> k;
      sol[i] = k;
    }
    sort(dra.begin(),dra.end());
    sort(sol.begin(),sol.end());
    bool flag;
    for(int i=0;i<n;i++)
    {
      flag = false;
      for(int j=0;j<sol.size();j++)
      {
        if (dra[i] <= sol[j])
        {
          //cout << "dra" << dra[i] << endl;
          //cout << "sol" << sol[j] << endl;
          ans += sol[j];
          sol.erase(sol.begin()+j);
          flag = true;
          break;
        }
      }
      if (!flag)
      {
        ans = -1;
        break;
      }

    }

    if (n > m)
    {
      cout << "Loowater is doomed!" << endl;
      continue;
    }
    if (ans>0) cout << ans << endl;
    else cout << "Loowater is doomed!" << endl;
  }
  return 0;
}
