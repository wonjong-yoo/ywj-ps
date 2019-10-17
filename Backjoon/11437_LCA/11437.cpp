#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

const int _MAX = 50001;

int parent[_MAX];
bool check[_MAX];
int depth[_MAX];
vector<vector<int>> edge(_MAX, vector<int>());


int lca(int u, int v) {
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
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N;
  cin >> N;
  

  for(int i = 0; i < N - 1; i++) {
    int from, to;
    cin >> from >> to;
    edge[from].push_back(to);
    edge[to].push_back(from);
    //parent[to] = from;
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
      int to = e;
      //int weight = e.second;
      if(!check[to]) {
        depth[to] = depth[x] + 1;
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
    
    cout << lca(a, b) << "\n";

  }
}