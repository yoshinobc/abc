#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,pair<int,int> > firstElof, pair<pair<int,int>,pair<int,int> > secondElof){
  return firstElof.first.second > secondElof.first.second;
}

bool cal(int x,int y,pair<pair<int,int>,pair<int,int> > line){
  if(line.second.first <= line.first.first){
    if(line.second.first > x || x >  line.first.first) return false;
    double h = line.second.second + x * (line.first.second-line.second.second) / (line.first.first - line.second.first);
    //cout << h << " " << y << endl;
    if (h <= y) return true;
    else return false;
  }
  else{
    if(line.first.first > x || x >  line.second.first) return false;
      double h = line.second.second + x * (line.second.second-line.first.second) / (line.second.first - line.first.first);
      if (h <= y) return true;
      else return false;
  }
}

vector<pair<pair<int,int>,pair<int,int> > > line;
vector<pair<int,int> > ps;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  int cases;
  cin >> cases;
  for(int c=0;c<cases;c++){
    int n,m;
    cin >> n;
    line.resize(n);
    for(int i=0;i<n;i++){
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if(y1 > y2) {
        line[i].first.first = x1;
        line[i].first.second = y1;
        line[i].second.first = x2;
        line[i].second.second = y2;
      }
      else{
        line[i].first.first = x2;
        line[i].first.second = y2;
        line[i].second.first = x1;
        line[i].second.second = y1;
      }
    }
    cin >> m;
    ps.resize(m);
    for(int i=0;i<m;i++){
      cin >> ps[i].first >> ps[i].second;
    }
    sort(line.begin(),line.end(),cmp);
    for(int i=0;i<m;i++){
      int x,y;
      x = ps[i].first;
      y = ps[i].second;
      for(int j=0;j<n;j++){
        bool iscatch;
        iscatch = cal(x,y,line[j]);
        //cout << "x " << x << "y " << y << "iscatch " << iscatch << " x " << line[j].first.first << " y " << line[j].first.second << endl;
        if (iscatch) {
          //cout << x << " " << y << endl;
          x = line[j].second.first;
          y = line[j].second.second;
        }
      }
      cout << x << endl;
    }
    if(c != cases-1) cout << endl;
  }
  return 0;
}
