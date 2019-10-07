#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<vector<int>> edge(N + 1, vector<int>());
  vector<int> indegree(N + 1, 0);
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    indegree[b]++;
  }

  queue<int> q;
  for(int i = 1; i <= N; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }

  while(!q.empty()) {
    int now = q.front();
    q.pop();

    if(indegree[now] == 0) {
      cout << now << " ";
    }

    // 연결된 노드를 찾는다.
    for(int outdegree : edge[now]) {
      indegree[outdegree]--;
      if(indegree[outdegree] == 0) {
        q.push(outdegree);
      }
    }
  }
}