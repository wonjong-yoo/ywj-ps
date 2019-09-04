#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <utility>

using namespace std;


// bool check(unordered_map<int, unordered_map<int, long long>> islandInfo, long long maxWeight, int src, int dst, int N) {

//   vector<int> stack;
//   vector<int> isVisited(N + 1, 0);

//   // 첫번째 방문 원소
//   stack.push_back(src);
//   while(stack.size() != 0) {
//     int now = stack.back();
//     stack.pop_back();

//     isVisited[now] = 1;

//     if(now == dst) {
//       //printf("HIT!\n");
//       return true;
//     }

//     for(const auto& nextDstAndWeight : islandInfo[now]) {
      
//       int nextDst = nextDstAndWeight.first;
//       long long nextWeight = nextDstAndWeight.second;
//       //printf("next dst : %d, next weight : %lld\n", nextDst, nextWeight);
//       //printf("%d %d\n", nextWeight <= maxWeight, isVisited[nextDst] == 0);
//       if(nextWeight <= maxWeight && isVisited[nextDst] == 0) {
//         stack.push_back(nextDst);
//       }
//     }
//   }
//   //printf("NOT HIT!\n");
//   return false;
// }

bool check(vector<vector<pair<int, long long>>> islandInfo, long long maxWeight, int src, int dst, int N) {

  vector<int> stack;
  vector<int> isVisited(N + 1, 0);

  // 첫번째 방문 원소
  stack.push_back(src);
  while(stack.size() != 0) {
    int now = stack.back();
    stack.pop_back();

    isVisited[now] = 1;

    if(now == dst) {
      //printf("HIT!\n");
      return true;
    }

    for(const auto& nextDstAndWeight : islandInfo[now]) {
      int nextDst = nextDstAndWeight.first;
      long long nextWeight = nextDstAndWeight.second;
      //printf("next dst : %d, next weight : %lld\n", nextDst, nextWeight);
      //printf("%d %d\n", nextWeight <= maxWeight, isVisited[nextDst] == 0);
      if(nextWeight >= maxWeight && isVisited[nextDst] == 0) {
        stack.push_back(nextDst);
      }
    }
  }
  //printf("NOT HIT!\n");
  return false;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  vector<vector<pair<int, long long>>> islandInfo(N + 1);
  //unordered_map<int, unordered_map<int, long long>> islandInfo;
  long long maxWeight = 1000000000;
  long long minWeight = 1;

  for(int i = 0; i < M; i++) {
    int src, dst;
    long long weight;
    scanf("%d %d %lld", &src, &dst, &weight);

    // if(islandInfo[src][dst] == 0) {
    //   islandInfo[src][dst] = weight;
    // } else {
    //   islandInfo[src][dst] = max(islandInfo[src][dst], weight);
    // }

    // if(islandInfo[dst][src] == 0) {
    //   islandInfo[dst][src] = weight;
    // } else {
    //   islandInfo[dst][src] = max(islandInfo[dst][src], weight);
    // }
    islandInfo[src].push_back(make_pair(dst, weight));
    islandInfo[dst].push_back(make_pair(src, weight));
  }

  int src, dst;
  scanf("%d %d", &src, &dst);

  long long left = minWeight;
  long long right = maxWeight;
  long long answer = 0;
  while(left <= right) {
    long long mid = (left + right) / 2;
    //printf("left : %lld, mid : %lld, right : %lld\n", left, mid, right);
    if(check(islandInfo, mid, src, dst, N)) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  printf("%lld", answer);

}