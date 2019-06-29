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
  int n;
  cin >> n;
  cin.ignore();
  for(int i=0;i<n;i++)
  {
    vector<int> v;
    string line;
    if (getline(cin,line))
    {
      istringstream ss(line);
      copy(istream_iterator<int>(ss), istream_iterator<int>(), back_inserter(v));
    }
    cout << "Case " << i+1 << ": " << *max_element(v.begin(),v.end()) << endl;
  }
  return 0;
}
