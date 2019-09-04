#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void recursion(int size, int index, int sum, vector<int>& set, vector<int>& history) {

  if(history.size() == 6) {
    for(int i = 0; i < history.size(); i++) {
      printf("%d ", history[i]);
    }
    printf("\n");
    return;
  }
  if(sum > 6) return;
  if(index > size) return;
  for(int i = index + 1; i < size; i++) {
    history.push_back(set[i]);
    recursion(size, i, sum + 1, set, history);
    history.pop_back(); ;
  }

}

int main() {
  int N;
  scanf("%d", &N);
  while(N != 0) {
    vector<int> set(N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &set[i]);
    }

    for(int i = 0; i <= N - 6; i++) {
      vector<int> history;
      history.push_back(set[i]);
      recursion(N, i, 0, set, history);
    }
    printf("\n");
    scanf("%d", &N);
  }
}