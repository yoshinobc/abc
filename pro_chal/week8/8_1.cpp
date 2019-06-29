#include <bits/stdc++.h>
using namespace std;

pair<int, int> peak;
vector<pair<int,int> > peaks;
vector<double> lenv;

bool pairCompare(pair<int,int> firstElof, pair<int,int> secondElof){
  return firstElof.first > secondElof.first;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  int c;
  cin >> c;
  for(int t=0;t<c;t++){
    peaks.clear();
    lenv.clear();
    int n;
    cin >> n;
    peaks.resize(n);
    lenv.resize(n);
    int x,y;
    for(int i=0;i<n;i++){
      cin >> peaks[i].first >> peaks[i].second;
    }
    sort(peaks.begin(),peaks.end(),pairCompare);
    x = peaks[0].first;
    y = peaks[0].second;
    double max_h = 0;
    for(int i=1;i<n;i++){
      if(max_h < peaks[i].second) {
        double x_ = peaks[i].first-x;
        //cout << "x" << x_ << endl;
        double y_ = peaks[i].second-y;
        //cout << "y_" << y_ << endl;
        double z = sqrt(x_*x_+y_*y_);
        //cout << "z" << z << endl;
        lenv[i] = z * (peaks[i].second-max_h)/(peaks[i].second-y);
        max_h = peaks[i].second;
      }
        //lenv[i] = hypot(y-peaks[i].second,peaks[i].first-x); //sqrt((y - peaks[i].second)*(y - peaks[i].second) + (peaks[i].first-x)*(peaks[i].first-x));
      else lenv[i] = 0;
      x = peaks[i].first;
      y = peaks[i].second;
    }
    double ans;
    //for(int i=0;i<lenv.size();i++) cout << lenv[i] << endl;
    cout << fixed;
    //cout << setprecision(2) << *std::max_element(lenv.begin(),lenv.end()) << endl;
    cout << setprecision(2) << accumulate(lenv.begin(),lenv.end(),0.0) << endl;
  }
  return 0;
}
