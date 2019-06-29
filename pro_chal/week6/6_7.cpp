#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  int count = 0;
  while(1){
    char str[10000000];
    cin >> str;
    int n[10000000];
    if (!strcmp(str,".")) break;
    n[0] = -1;
    int i=1;
    int j=-1;
    //cout << str.length() << endl;
    int num = strlen(str);
    while(str[i]){
      //cout << str[i] << endl;
      //cout << i << " " << num << endl;
      while(j >= 0 && str[j+1] != str[i]) j = n[j];
      if(str[j+1] == str[i]) j++;
      n[i] = j;
      i++;
    }
    count++;
    cout << num / (num - j - 1) << endl;
    //cout << count << " " << str << " " << num / (num - j-1) << endl;
  }
  return 0;
}
