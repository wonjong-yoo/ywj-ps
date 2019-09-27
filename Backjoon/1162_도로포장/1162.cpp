#include <unordered_map>
#include <unordered_set>
#include <set>

#include <cstdio>
#include <algorithm>
#include <utility>


using namespace std;

int N, M, K;

int road[10001][10001];

int calc(set<int>* linkedCity, unordered_set<int>& visited, unordered_map<int, pair<int, int>>* costs,  int nowCity) {

  if(visited.find(nowCity) != visited.end()) {
    return 0;
  } 
  
  if(nowCity == N) {
    return -1;
  }
  visited.insert(nowCity);

  for(auto iter : linkedCity[nowCity]) {
    int nextCity = iter;

    int result = calc(linkedCity, visited, costs, iter);
    if(result == -1) {
      costs[]
    }

  }

  visited.erase(nowCity);
}


int main() {
  scanf("%d %d %d", &N, &M, &K);
  

  // A에서 목적지까지 갈때 거리, 비용
  unordered_map<int, pair<int, int>> costs[N + 1];
  set<int> linkedCity[N + 1];

  for(int i = 0; i < M; i++) {
    int a, b, cost;
    scanf("%d %d %d", &a, &b, &cost);
    road[a][b] = cost;
    road[b][a] = cost;
    linkedCity[a].insert(b);
    linkedCity[b].insert(a);
  }

  
}