#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int parent[1000001];

int findParent(int i) {
  if(parent[i] == i) return i;
  return findParent(parent[i]);
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i = 0; i <= N; i++) {
    parent[i] = i;
  }
  for(int i = 0; i < M; i++) {
    int a, b;
    int mode;
    scanf("%d %d %d", &mode, &a, &b);
    if(mode == 0) {
      // a, b 둘다 최상위 부모일 경우
      if(parent[a] == a && parent[b] == b) {
        // a는 자기 자신을 가리키고 b는 a를 가리키도록
        parent[a] = a;
        parent[b] = a;
      } else if(parent[a] != a && parent[b] == b) {
        parent[findParent(a)] = b;
      } else if(parent[a] == a && parent[b] != b) {
        parent[findParent(b)] = a;
      } else {
        parent[findParent(a)] = findParent(b);
      }
    } else if (mode == 1) {
      if(findParent(a) == findParent(b)) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
}