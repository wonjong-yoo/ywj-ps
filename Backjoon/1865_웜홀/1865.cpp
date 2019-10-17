#include <tuple>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int TC;
  cin >> TC;
  for(int t = 0; t < TC; t++) {
    int N, M, W;
    cin >> N >> M >> W;
    vector<tuple<int, int, int>> edge;
    for(int i = 0; i < M; i++) {
      int from, to, weight;
      cin >> from >> to >> weight;
      edge.push_back({from, to, weight});
      edge.push_back({to, from, weight});
    }

    for(int i = 0; i < W; i++) {
      int from, to, weight;
      cin >> from >> to >> weight;
      edge.push_back({from, to, -weight});
    }

    bool isNegativeCycle = false;

    vector<int> time(N + 1, __INT32_MAX__);
    time[1] = 0;

    for(int v = 1; v <= N; v++) {
      for(const auto& tp : edge) {
        int from = get<0>(tp);
        int to = get<1>(tp);
        int weight = get<2>(tp);
        
        if(time[from] == __INT32_MAX__) continue;

        if(time[to] > time[from] + weight) {
          time[to] = time[from] + weight;
          if(v == N) {
            isNegativeCycle = true;
          }
        }
      }
    }

    if(isNegativeCycle) cout << "YES\n";
    else cout << "NO\n";
  }
}