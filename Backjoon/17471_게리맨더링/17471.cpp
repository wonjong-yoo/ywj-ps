#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

pair<int, int> CountAndSum(vector<bool>& visited, vector<vector<int>>& edge, vector<int>& population) {
  queue<int> q;
  vector<bool> visitedInQueue = visited;

  for(int i = 1; i <= visitedInQueue.size() - 1; i++) {
    if(visitedInQueue[i] == false) {
      q.push(i);
      break;
    }
  }
  int count = 0;
  int sum = 0;
  

  while(!q.empty()) {
    int v = q.front();
    q.pop();
    
    if(visitedInQueue[v]) continue;
    
    visitedInQueue[v] = true;
    
    for(int to : edge[v]) {
      q.push(to);
    }
    sum += population[v];
    count++;
  }

  return make_pair(count, sum);
}

int answer = __INT32_MAX__;
set<int> f;
void dfs(int now, int sum, int visitCount, vector<bool>& visited, vector<vector<int>>& edge, vector<int>& population) {
  
  // 현재 방문한 정점에 대해서 나머지가 모두 연결가능한지 확인한다.
  
  if(visited[now]) return;

  
  visitCount++;
  sum += population[now];
  visited[now] = true;
  auto p = CountAndSum(visited, edge, population);
  visited[now] = false;
  
  int sectionTwoCount = p.first;
  int sectionTwoSum = p.second;

  //for(int i = 1; i <= population.size() - 1; i++) {
  //  cout << visited[i] << " ";
  //}
  //cout << endl;
  //cout << "Count A : " << visitCount << ", B : " << sectionTwoCount << endl;
  //cout << "Sum A : " << sum << ", B : " << sectionTwoSum << endl;
  if(visitCount + sectionTwoCount == population.size() - 1) {
    
    int diff = std::abs(sum - sectionTwoSum);
    if(answer > diff) answer = diff;
    else {
      return;
    }

    //answer = min(answer, std::abs(sum - sectionTwoSum));
     
  }

  
  for(int& to : edge[now]) {
    //cout << "from " << now << " to " << to << endl;
    visited[now] = true;
    dfs(to, sum, visitCount, visited, edge, population);
    visited[now] = false;
  }
  


}

int main() {
  int N;
  cin >> N;
  vector<int> population(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> population[i];
  }

  vector<vector<int>> edge(N + 1, vector<int>());

  for(int from = 1; from <= N; from++) {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
      int to;
      cin >> to;
      
      edge[from].push_back(to);
    }
    

  }

  
  // 모든 정점을 백트래킹한다.
  for(int start = 1; start <= 1; start++) {
    vector<bool> isVisited(N + 1, false);
    dfs(start, 0, 0, isVisited, edge, population);
  }

  if(answer == __INT32_MAX__) {
    cout << "-1\n";
  } else cout << answer << endl;

  return 0;
}