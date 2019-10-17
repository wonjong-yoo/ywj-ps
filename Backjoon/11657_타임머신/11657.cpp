#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>


using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> edge;

  vector<int> time(N + 1, __INT32_MAX__);
  time[1] = 0;
  for(int i = 0; i < M; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    edge.push_back({from, to, weight});
  }


  // 선택된 정점의 개수
  bool negativeCycle = false;
  for(int v = 1; v <= N; v++) {
    for(const auto& p : edge) {
      int from = get<0>(p);
      int to = get<1>(p);
      int weight = get<2>(p);
      if(time[from] == __INT32_MAX__) continue;
      if(time[to] > time[from] + weight) {
        time[to] = time[from] + weight;
        if(v == N) {
          negativeCycle = true;
        }
      }
    }
  }
    


  // for(int i = 1; i <= N; i++) {
  //   cout << time[i] << " ";
  // }




  if(negativeCycle) {
    cout << "-1" << endl;
    return 0;
  }
  for(int i = 2; i <= N; i++) {
    if(time[i] != __INT32_MAX__) cout << time[i] << endl;
    else cout << "-1" << endl;
  }



}