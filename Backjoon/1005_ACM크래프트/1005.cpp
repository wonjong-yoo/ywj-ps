#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int recursion(int nowPosition, vector<int>& cost, set<int>* edge, vector<int>& memorization, vector<bool>& visited) {
  if(visited[nowPosition]) {
    return memorization[nowPosition];
  }

  if(edge[nowPosition].empty()) {
    return cost[nowPosition];
  }

  visited[nowPosition] = true;
  int answer = 0;
  for(auto iter = edge[nowPosition].begin(); iter != edge[nowPosition].end(); iter++) {
    int previousPosition = *iter;
    int result = recursion(previousPosition, cost, edge, memorization, visited);
    
    answer = max(result, answer);
  }
  memorization[nowPosition] = answer + cost[nowPosition];

  return answer + cost[nowPosition];
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> cost(N, 0);
    for(int i = 0; i < N; i++) {
      scanf("%d", &cost[i]);
    }

    set<int> edge[N];
    for(int i = 0; i <K; i++) {
      int from, to;
      scanf("%d %d", &from, &to);
      edge[to - 1].insert(from - 1);
    }
    int W;
    scanf("%d", &W);
    W--;
    vector<int> memorization(N, 0);
    vector<bool> visited(N, false);
    printf("%d\n", recursion(W, cost, edge, memorization, visited));
  }  
}