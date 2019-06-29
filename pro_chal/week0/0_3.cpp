#include <bits/stdc++.h>
using namespace std;
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

typedef pair<int,int> ipair;
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
bool greaterPair(const ipair& l, const ipair& r){return l.second > r.second;}
int search_hotel(int j,vector<int> prices)
{
  vector<ipair> v;
  for(int i=0;i<prices.size();i++)
  {
    v.push_back(ipair(i,prices[i]));
  }
  sort(v.begin(),v.end(),lessPair);
  int count = 0;
  int ans;
  for(vector<ipair>::iterator it = v.begin(); it != v.end(); ++it)
  {
    if(count == j)
    {
      ans = it->first;
      break;
    }
    count++;
  }
  return ans;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());
  vector<int> ans;
  while(1)
  {
    if(cin.eof()) break;
    int n=0;
    int b,h,w;
    cin >> n >> b >> h >> w;
    vector<int> price(h);
    vector<vector<int> > v(h,vector<int>(w));
    bool flag = true;
    int min_money = 99999999;
    for(int i=0;i<h;i++)
    {
      cin >> price[i];
      for(int j=0;j<w;j++){
        cin >> v[i][j];
      }
    }
    for(int hotel=0;hotel<h;hotel++)
    {
      int money=-1;
      for(int room=0;room<w;room++)
      {
        if(v[hotel][room]>=n)
        {
          money=price[hotel]*n;
        }
      }
      if (money <= min_money && money != -1) min_money = money;
    }
    if (n==0) break;
    if (min_money <= b) cout << min_money << endl;
    else cout << "stay home" << endl;
  }
  return 0;
}
