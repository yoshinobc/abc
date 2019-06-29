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
  for(int c=0;c<cases;c++)
  {
    int A,B,C;
    bool flag = false;
    cin >> A >> B >> C;
    for(int x=-100;x<=100;x++)
    {
      for(int y=x+1;y<=100;y++)
      {
        for(int z=y+1;z<=100;z++)
        {
          if ((x+y+z==A) && (x*y*z==B) && (x*x+y*y+z*z==C))
          {
            cout << x << " " << y << " " << z << endl;
            flag = true;
          }
        }
      }
    }
    if (!flag) cout << "No solution." << endl;
  }
  return 0;
}
