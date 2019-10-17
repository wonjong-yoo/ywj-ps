#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int findLevel(int vertex, vector<vector<pair<int, int>>>& edge, vector<int>& parent){
  int now = vertex;
  int depth = 0;
  while(parent[now] != -1) {
    now = parent[now];
    depth++;
  }

  return depth;
}


int lca(int u, int v, vector<int>& depth, vector<int>& parent) {
  if(depth[u] < depth[v]) {
    swap(u, v);
  }
  while(depth[u] != depth[v]) {
    u = parent[u];
  }

  while(u != v) {
    u = parent[u];
    v = parent[v];
  }

  return u;
}

int main() {
  int N;
  cin >> N;
  vector<int> parent(N + 1, 0);
  vector<bool> check(N + 1, false);
  vector<int> depth(N + 1, 0);
  vector<int> dist(N + 1, 0);
  vector<vector<pair<int, int>>> edge(N + 1, vector<pair<int, int>>());

  for(int i = 0; i < N - 1; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    edge[from].push_back({to, weight});
    edge[to].push_back({from, weight});
    parent[to] = from;
    
  }


  // 1번이 루트인 트리를 만든다.
  depth[1] = 0;
  check[1] = true;
  queue<int> q;
  
  q.push(1);
  parent[1] = 0;

  while(!q.empty()) {
    int x = q.front();
    q.pop();
    for(const auto& e : edge[x]) {
      int to = e.first;
      int weight = e.second;
      if(!check[to]) {
        depth[to] = depth[x] + 1;
        dist[to] = dist[x] + weight;
        check[to] = true;
        parent[to] = x;
        q.push(to);
      }
    }
  } 

  int M;
  cin >> M;
  for(int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    // 각 정점의 Level을 구한다.
    
    cout << dist[a] + dist[b] - 2 * dist[lca(a, b, depth, parent)] << endl;

  }
}