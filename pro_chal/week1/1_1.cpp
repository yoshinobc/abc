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
    int b;
    int s = 0;
    //ifstream in("input.txt");
    //cin.rdbuf(in.rdbuf());
    int l,r;
    cin >> s >> b;
    int sol_l[s];
    int sol_r[s];
    int outl,outr;
    for(int i=0;i<s;i++)
    {
      sol_l[i] = i-1;
      if(i==s-1) sol_r[i] = -1;
      else sol_r[i] = i+1;
    }
    outr = -1;
    outl = -1;
    for(int i=0;i<b;i++)
    {
      cin >> l >> r;
      l--;
      r--;
      outl = sol_l[l];
      outr = sol_r[r];
      sol_l[sol_r[r]] = outl;
      sol_r[sol_l[l]] = outr;
      if (outl == -1 && outr == -1) cout << "* " <<  "*" << endl;
      else if(outl == -1) cout << "* " << outr+1 << endl;
      else if(outr == -1)  cout << outl+1 << " *" << endl;
      else cout << outl+1 << " " << outr+1 << endl;
    }
    if (s==0) break;
    cout << "-" << endl;
  }
  //cout << endl;
  return 0;
}
