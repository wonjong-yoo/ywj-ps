#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<vector<int>> W(N, vector<int>(N, 0));

  for(int i = 0; i < N; i++) {
    for(int k = 0; k < N; k++) {
      scanf("%d", &W[i][k]);
    }
  }

  vector<int> cities(N);
  for(int i = 0; i < N; i ++) {
    cities[i] = i;
  }

  int answer = __INT_MAX__;

  do {

    bool flag = false;
    int sum = 0;
    for(int i = 0; i < N - 1; i++) {
      int nowPath = W[cities[i]][cities[i + 1]];
      if (nowPath == 0) {
        flag = true;
        break;
      }
      sum += nowPath;
    }
    if(flag) continue;
    //마지막 도시로부터 처음 도시로 오는 비용을 더한다.
    int finalPath = W[cities[N - 1]][cities[0]];
    if(finalPath != 0) {
      sum += finalPath;
    
      answer = min(answer, sum);
    }
   
    
  } while(next_permutation(cities.begin() + 1, cities.end()));

  printf("%d\n", answer);
}