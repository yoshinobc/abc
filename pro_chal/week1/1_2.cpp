#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<int> >& table)
{
  for(int i=1;i<4;i++)
  {
    for(int j=1;j<4;j++)
    {
      if(table[i][j] == 1) return true;
    }
  }
  return false;
}

void update(vector<vector<int> >& table)
{
  vector<int> v(9);
  int c=0;
  for(int i=1;i<4;i++)
  {
    for(int j=1;j<4;j++)
    {
      v[c] = table[i-1][j] + table[i+1][j] + table[i][j-1] + table[i][j+1];
      c++;
    }
  }
  c=0;
  for(int i=1;i<4;i++)
  {
    for(int j=1;j<4;j++)
    {
      table[i][j] = v[c]%2;
      c++;
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  vector<vector<int> > table(5,vector<int>(5));
  unsigned int N;
  cin >> N;
  while(N--)
  {
    for(int j=0;j<5;j++)
    {
      if (j == 0 || j == 4) table[j][0],table[j][1],table[j][2],table[j][3],table[j][4] = 0,0,0,0;
      else
      {
        for(int i=1;i<4;i++) {
            char a;
            cin >> a;
            table[j][i] = (int)a - 48;
        }
\
      }
    }
    int count = -1;
    while(check(table))
    {
      count++;
      update(table);
    }
    cout << count << endl;
  }
  return 0;
}
