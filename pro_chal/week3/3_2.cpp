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
  for(int c=1;c<=cases;c++){
    int lines;
    cin >> lines;
    int s,e,max_s,max_e,sum_v,max_v;
    sum_v = -1;
    s = -1;
    e = -1;
    max_v = 0;
    for(int l=1;l<lines;l++){
      int num;
      cin >> num;
      if(sum_v >= 0) sum_v += num;
      else{
        sum_v = num;
        s = l;
      }
      if (sum_v > max_v || (sum_v == max_v && l+1 - s > max_e - max_s)){
        max_v = sum_v;
        max_s = s;
        max_e = l+1;
      }
    }
    if (max_v == 0) cout << "Route " << c << " has no nice parts" << endl;
    else cout << "The nicest part of route " << c << " is between stops " << max_s << " and " << max_e << endl;
  }
  return 0;
}
