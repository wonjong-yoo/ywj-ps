#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int dx[3] = {1, 0, 1};
int dy[3] = {1, 1, 0};
int board[1001][1001];
int memorization[1001][1001];
int N, M;
void recursion(int y, int x, int nowSum) {
  int maxY = N;
  int maxX = M;
  if(y < 0 || x < 0 || x >= maxX || y >= maxY) return;

  nowSum += board[y][x];
  //printf("(%d, %d) : %d\n", x, y, nowSum);
  if(memorization[y][x] == 0) {
    memorization[y][x] = nowSum;
  } else if(memorization[y][x] > nowSum) {
    return;
  } else {
    memorization[y][x] = nowSum;
  }

  for(int i = 0; i < 3; i++) {
    recursion(y + dy[i], x + dx[i],nowSum);
  }

}

int max3(int a, int b, int c) {
  return max(a, max(b, c));
}

int main() {

  scanf("%d %d", &N, &M);

  for(int y = 1; y <= N; y++) {
    for(int x = 1; x <= M; x++) {
      scanf("%d", &board[y][x]);
    }
  }  

  for(int y = 1; y <= N; y++) {
    for(int x = 1; x <= M; x++) {
      memorization[y][x] = max3(memorization[y - 1][x], memorization[y][x - 1], memorization[y - 1][x - 1]) + board[y][x];
    }
  }

  printf("%d\n", memorization[N][M]);

}