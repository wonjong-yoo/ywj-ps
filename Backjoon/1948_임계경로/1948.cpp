#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
// #include <unordered_set>
#include <set>
#include <map>

using namespace std;

// auto vhash = [](const pair<int, int>& e) {
//   return (size_t)(e.first * 10000 + e.second);
// };

// auto vequal = [](const pair<int, int>& lv, const pair<int, int>& rv) {
//   return ((lv.first == rv.first) && (lv.second == rv.second));
// };

auto comp = [](const pair<int, int>& left, const pair<int, int>& right) {
  int l = left.first * 100000 + left.second;
  int r = right.first * 100000 + right.second;
  return l < r;
};
int main() {

  int N, M;
  cin >> N >> M;
  
  //vector<vector<int>> weight(N + 1, vector<int>(N + 1, 0));
  
  vector<unordered_map<int, int>> weight(N + 1, unordered_map<int, int>());

  vector<vector<int>> edge(N + 1, vector<int>());
  vector<int> indegree(N + 1);

  for(int i = 0; i < M; i++) {
    int from, to, time;
    cin >> from >> to >> time;
    weight[from][to] = time;
    edge[from].push_back(to);
    indegree[to]++;
  }

  int f, t;
  cin >> f >> t;



 // using EdgeHash = std::set<pair<int, int>, decltype(vhash), decltype(vequal)>;
  using EdgeHash = set<pair<int, int>, decltype(comp)>;

  // vector<pair<int, EdgeHash>> answer(N + 1, {0, EdgeHash(comp)});
  vector<int> time(N + 1, 0);
  queue<int> q;
  for(int i = 1; i <= N; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }
  //q.push(f);

  while(!q.empty()) {
    int from = q.front();
    q.pop();

    for(int to : edge[from]) {
      // if(answer[to].first < answer[from].first + weight[from][to]) {
      //   answer[to].first = answer[from].first + weight[from][to];
      //   answer[to].second.clear();
      //   answer[to].second.insert(answer[from].second.begin(), answer[from].second.end());
      //   answer[to].second.insert({from, to});
      // } else if(answer[to].first == answer[from].first + weight[from][to]) {
      //   answer[to].second.insert(answer[from].second.begin(), answer[from].second.end());
      //   answer[to].second.insert({from, to});
      // }
      time[to] = max(time[to], time[from] + weight[from][to]);

      indegree[to]--;
      if(indegree[to] == 0) {
        q.push(to);
      }
    }
  }

  // 에지를 뒤집는다.
  //vector<unordered_map<int, int>> rWeight(N + 1, unordered_map<int, int>());
  vector<vector<int>> rEdge(N + 1, vector<int>());

  for(int from = 1; from <= N; from++) {
    for(int to : edge[from]) {
      rEdge[to].push_back(from);
    }

    // for(const auto& iter : weight[from]) {
    //   rWeight[iter.first][from] = weight[from][iter.first];
    // }
  }

  queue<int> rq;
  rq.push(t);
  int answer = 0;

  EdgeHash visit = EdgeHash(comp);

  while(!rq.empty()) {
    int from = rq.front();
    rq.pop();
    
    for(int to : rEdge[from]) {
      if(time[from] - time[to] == weight[to][from]) {
        if(visit.find({from, to}) != visit.end()) {
          continue;
        }
        answer++;
        rq.push(to);
        visit.insert({from, to});
      }
    }
  }

  cout << time[t] << endl << answer;

  // for(int i = 1; i <= N; i++) {
  //   cout << time[i] << endl;
  // }

  // for(pair<int, int> a : answer[t].second) {
  //   cout << a.first << ", " << a.second << endl;
  // }

  //cout << answer[t].first << "\n" << answer[t].second.size();
  
}