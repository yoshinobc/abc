#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,t,t_med1,t_med2;
  vector<int> nums;
  vector<int> t_nums;

  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> t;
    nums.push_back(t);
  }
  t_nums = nums;
  sort(t_nums.begin(),t_nums.end());
  t_med1 = t_nums[t_nums.size()/2-1];
  t_med2 = t_nums[t_nums.size()/2];
  for(int i = 0;i < n;i++){
    if(nums[i] <= t_med1){
      cout << t_med2 << endl;
    }
    else{
      cout << t_med1 << endl;
    }
  }
  return 0;
}
