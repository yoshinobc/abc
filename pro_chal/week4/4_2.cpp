#include <bits/stdc++.h>
using namespace std;

typedef queue<int> IntQueue;
vector<int> graph_ans;
vector<int> visited;

int dfs (int i,vector<int>&graph){
  if(visited[i]) return 0;
  visited[i] = 1;
  int k = dfs(graph[i],graph);
  visited[i] = 0;
  graph_ans[i] = k + 1;
  return graph_ans[i];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //ifstream in("input.txt");
    //cin.rdbuf(in.rdbuf());
    int cases;
    cin >> cases;
    for(int c=0;c<cases;c++){
        int n;
        cin >> n;
        vector<int> graph(n);
        graph_ans.resize(n);
        visited.resize(n);

        for(int i=0;i<n;i++) graph[i] = 0;
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            graph[a-1] = b-1;
        }
        for(int i=0;i<n;i++) graph_ans[i] = -1;
        for(int i=0;i<n;i++) if(graph_ans[i] == -1) dfs(i,graph);
        /*
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            cout << graph_ans[i][j];
          }
          cout << endl;
        }
        */
        int count = 0;
        int max_count = -1;
        int maxid = -1;
        for(int i=0;i<n;i++){
          count = graph_ans[i];
          if (count > max_count){
            max_count = count;
            maxid = i;
          }
        }
        //cout << max_element(graph_ans,graph_ans+n)- n+1;
        /*
        for(int i=0;i<n;i++){
            count = 0;
            for(int j=0;j<n;j++) if(graph_ans[i][j]) count++;
            //count = accumulate(graph_ans[i].begin(),graph_ans[i].end(),0);
            //cout << count << endl;
            if (max_count < count){
                max_count = count;
                max_id = i;
            }
        }
        */
        cout << "Case " << c+1 << ": " << maxid+1 << endl;
    }
    return 0;
}
