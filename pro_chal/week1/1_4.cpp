#include <bits/stdc++.h>
using namespace std;


struct UnionFind
{
  vector<int> par;
  UnionFind(int N) : par(N)
  {
    for(int i=0;i<N;i++) par[i] = i;
  }

  int root(int x)
  {
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x,int y)
  {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
  }

  bool same(int x, int y)
  {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  int n;
  cin >> n;
  UnionFind tree(2*n+2);

  while(true)
  {
    int c,x,y;
    cin >> c >> x >> y;
    if (c == 0) break;
    int ans = -2;
    if (c==1)
    {
      if(tree.same(2*x,2*y+1) || tree.same(2*x+1,2*y)) ans = -1;
      else {
        tree.unite(2*x,2*y);
        tree.unite(2*x+1,2*y+1);
      }
    }
    else if(c==2)
    {
      if(tree.same(2*x,2*y) || tree.same(2*x+1,2*y+1)) ans = -1;
      else {
        tree.unite(2*x+1,2*y);
        tree.unite(2*x,2*y+1);
      }
    }
    else if(c==3)
    {
      if(tree.same(2*x,2*y) || tree.same(2*x+1,2*y+1)) ans = 1;
      else ans = 0;
    }
    else if(c==4)
    {
      if(tree.same(2*x+1,2*y) || tree.same(2*x,2*y+1)) ans = 1;
      else ans = 0;
    }

    if(ans != -2) cout << ans << endl;

  }
  return 0;
}
