#include <bits/stdc++.h>
using namespace std;
int main()
{
  //cin.tie(0);
  //ios::sync_with_stdio(false);

  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  map<char,int> charval;
  map <char, int>::iterator it;

  int N;
  cin >> N;
  for(int cn=0;cn<N;cn++)
  {
    int k;
    long long int ans = 0;
    char s;
    long long int val;
    cin >> k;
    charval.clear();
    for(int i=0;i<k;i++)
    {
      cin >> s >> val;
      charval[s] = val;
    }
    int len_num;
    cin >> len_num;
    string test;
    getline(cin,test);
    for(int i=0;i<len_num;i++)
    {
      string line;
      getline(cin,line);
      for(int j=0;j<line.size();j++)
      {
        char c = line[j];
        it = charval.find(c);
        if (it != charval.end()) ans += it->second;
      }
    }
    //cout << ans / 100 << ".";
    //cout << ans % 100 << "$" << endl;
    printf("%d.%02d$\n",ans/100,ans%100);
  }
  return 0;
}
