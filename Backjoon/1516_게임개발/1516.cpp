#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> weight(N + 1);
  vector<vector<int>> edge(N + 1, vector<int>());
  vector<int> indegree(N + 1, 0);
  
  for(int i = 1; i <= N; i++) {
    cin >> weight[i];

    while(1) {
      int to;
      cin >> to;
      if(to == -1) break;
      edge[to].push_back(i);
      indegree[i]++;
    }
  }

  queue<int> q;
  vector<int> minTime(N + 1, 0);


  for(int i = 1; i <= N; i++) {
    if(indegree[i] == 0) {
      minTime[i] = weight[i]; 
      q.push(i);
    }
  }

  

  while(!q.empty()) {
    int nowNode = q.front();
    q.pop();

    for(int to : edge[nowNode]) {
      minTime[to] = max(minTime[to], minTime[nowNode] + weight[to]);

      indegree[to]--;
      if(indegree[to] == 0) {
        q.push(to);
      }
    }

  }

  for(int i = 1; i <= N; i++) {
    cout << minTime[i] << "\n";
  }

}