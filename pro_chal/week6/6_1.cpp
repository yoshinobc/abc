#include <bits/stdc++.h>
using namespace std;
bool comp(const string& lh, const string& rh) {
     return lh.length() < rh.length();
}
/*
struct Node{
  char c;
  Node* zero;
  Node* one;
};

struct  Tree{
  char c;
  Node* root;
};

void initTree(Tree tree){
  tree->c = ' ';
  tree->root = nullptr;
}

void InitNode(Node* node,char c){
  node->c = c;
  node->zero = nullptr;
  node->one = nullptr;
}
/*
bool add(string line,struct Tree* root){
  bool flag = false;
  for(int i=0;i<line.size();i++){
    if(line[i]==0){
      if(root->zero == nullptr){
        struct Node *node;
        root->zero = node;
        root->zero->c = '0';
        root = root->zero;
        line = line.substr(1);
        flag = true;
      }
      else{
        root = root->zero;
        line = line.substr(1);
      }
    }
    else{
      if(root->one == nullptr){
        struct Node *node;
        root->one = node;
        root->one->c = '1';
        root = root->one;
        line = line.substr(1);
        flag = true;
      }
      else{
        root = root->zero;
        line = line.substr(1);
      }
    }
  }
  return flag;
}
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  vector<string> lines;
  int count = 1;
  while(1){
    bool flag = false;
    string line;
    line = "test";
    cin >> line;
    string s;
    string t;
    if(line == "test") break;
    if(line == "9") {
      sort(lines.begin(),lines.end(),comp);
      for(int i=0;i<lines.size() && !flag;i++){
        for(int j=i+1;j<lines.size() && !flag;j++){
          s = lines[i];
          t = lines[j];
          bool flag2 = true;
          //cout << s << " " << t << endl;
          for(int k=0;k<s.size();k++){
            if(s[k] != t[k]) flag2 = false;
          }
          if(flag2){
            flag = true;
            break;
          }
        }
      }
      if(!flag) cout << "Set " << count <<" is immediately decodable" << endl;
      else cout << "Set " << count << " is not immediately decodable" << endl;
      lines.clear();
      count++;
    }
    lines.push_back(line);
  }
  return 0;
}
