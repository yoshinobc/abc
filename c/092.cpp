#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t,n;

  cin >> n;

  vector<int> nums;
  vector<int> t_nums;
  vector<int> t2_nums;
  vector<int> t3_nums;

  int sum1;
  int sum2;
  int sum3;

  for(int i= 0;i < n;i++){
    cin >> t;
    nums.push_back(t);
  }

  t_nums = nums;

  sort(t_nums.begin(),t_nums.end());
  if(t_nums[0] < 0 && t_nums[n-1] > 0){
    sum1 = abs(t_nums[0] * 2) + abs(t_nums[n-1] * 2);
  }
  else if(t_nums[0] < 0 && t_nums[n-1] <= 0){
    sum1 = abs(t_nums[0] * 2) + abs(t_nums[n-1] * 0);
  }
  else if(t_nums[0] >= 0 && t_nums[n-1] > 0){
    sum1 = abs(t_nums[0] * 0) + abs(t_nums[n-1] * 2);
  }
  else{
    sum1 = abs(t_nums[0] * 1) + abs(t_nums[n-1] * 1);
  }

  for(int i = 0;i < n;i++){
    if(nums[i] == t_nums[0]){
      t2_nums = nums;
      t2_nums.erase(t2_nums.begin()+i);
      n-=1;
      sort(t2_nums.begin(),t2_nums.end());
      if(t2_nums[0] < 0 && t2_nums[n-1] > 0){
        sum2 = abs(t2_nums[0] * 2) + abs(t2_nums[n-1] * 2);
      }
      else if(t2_nums[0] < 0 && t2_nums[n-1] <= 0){
        sum2 = abs(t2_nums[0] * 2) + abs(t2_nums[n-1] * 0);
      }
      else if(t2_nums[0] >= 0 && t2_nums[n-1] > 0){
        sum2 = abs(t2_nums[0] * 0) + abs(t2_nums[n-1] * 2);
      }
      else{
        sum2 = abs(t2_nums[0] * 2) + abs(t2_nums[n-1] * 2);
      }
      n+=1;
      cout << sum2 << endl;
    }
    else if(nums[i] == t_nums[n-1]){
      t3_nums = nums;
      t3_nums.erase(t3_nums.begin()+i);
      n -=1;
      sort(t3_nums.begin(),t3_nums.end());
      if(t3_nums[0] < 0 && t3_nums[n-1] > 0){
        sum3 = abs(t3_nums[0] * 2) + abs(t3_nums[n-1] * 2);
      }
      else if(t3_nums[0] < 0 && t3_nums[n-1] <= 0){
        sum3 = abs(t3_nums[0] * 2) + abs(t3_nums[n-1] * 0);
      }
      else if(t3_nums[0] >= 0 && t3_nums[n-1] > 0){
        sum3 = abs(t3_nums[0] * 0) + abs(t3_nums[n-1] * 2);
      }
      else{
        sum3 = abs(t3_nums[0] * 1) + abs(t3_nums[n-1] * 1);
      }
      n+=1;
      cout << sum3 << endl;
    }
    else{
      cout << sum1 << endl;
    }
  }
  return 0;
}
