#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int recursion(int nowPosition, vector<int>& cook_times, unordered_set<int>* edges, vector<bool> &visited) {
  cout << "now Position : " << nowPosition + 1 << "\n";
  if(edges[nowPosition].empty()) {
    visited[nowPosition] = true;
    return cook_times[nowPosition];
  }

  

  visited[nowPosition] = true;

  int answer = 0;

  for (auto iter = edges[nowPosition].begin(); iter != edges[nowPosition].end(); iter++) {
    int previousPosition = *iter;
    int result = recursion(previousPosition, cook_times, edges, visited);
    answer = max(answer, result);
  }

  return answer;
}

vector<int> solution(vector<int> cook_times, vector<vector<int>> order, int k) {
  vector<int> answer(2, 0);
  unordered_set<int> edges[cook_times.size()];

  for(int i = 0; i < order.size(); i++) {
    int from = order[i][0];
    int to = order[i][1];
    edges[to - 1].insert(from - 1);
  }

  // for(i = 0; i < cook_times.size(); i++) {
  //   for(auto iter = edges[nowPosition].begin(); iter != edges[nowPosition].end(); iter++) {
      
  //   }
  // }

  vector<bool> visited(cook_times.size(), false);

  int minTime = recursion(k - 1, cook_times, edges, visited);

  int visitedNum = 0;
  for(int i = 0; i < visited.size(); i++) {
    if(visited[i]) ++visitedNum;
  }
  answer[0] = visitedNum;
  answer[1] = minTime;
  cout << "visit : " << visitedNum << " minTime : " << minTime << endl;
  return answer;
}

int main() {
  
  int N;
  cin >> N;
  vector<int> cook_times(N, 0);
  for(int i = 0; i < N; i++) { 
    cin >> cook_times[i];
  }

  int M;
  cin >> M;
  vector<vector<int>> order;
  for(int i = 0; i < N; i++) {
    vector<int> t(2, 0);
    cin >> t[0] >> t[1];

    order.push_back(t);
  }

  int k;
  cin >> k;

  solution(cook_times, order, k);

  
}