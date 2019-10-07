#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> edge(N + 1, vector<int>());
  vector<int> indegree(N + 1);
  vector<int> times(N + 1);
  for(int i = 1; i <= N; i++) {
    int time;
    int M;
    cin >> time >> M;
    times[i] = time;
    for(int k = 0; k < M; k++) {
      int out;
      cin >> out;
      edge[out].push_back(i);
      indegree[i]++;
    }
  }
  vector<int> maxTime(N + 1);
  queue<pair<int, int>> q;
  for(int i = 1; i <= N; i++) {
    if(indegree[i] == 0) {
      maxTime[i] = times[i];
      q.push({i, times[i]});
    }
  }
  
  while(!q.empty()) {
    int nowNode = q.front().first;
    int nowTime = q.front().second;
    q.pop();
    
    for(int out : edge[nowNode]) {
      maxTime[out] = max(maxTime[out], maxTime[nowNode] + times[out]);
      indegree[out]--;
      if(indegree[out] == 0) {
        q.push({out, maxTime[out]});
      }
    }
        
  }
  int answer = 0;
  for(int i = 1; i <= N; i++) {
    answer = max(answer, maxTime[i]);
  }
  cout << answer << endl;
}