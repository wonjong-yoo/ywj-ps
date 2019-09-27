#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int recursion(int N, int nowX, int nowY, int x1, int y1, int x2, int y2, int start) {
  
  if(N == 1) return start;

  int size = N / 2;
  // 1사분면 검사
  if(nowX >= x1 && nowY >= y1 && nowX <= x1 + size - 1 && nowY <= y1 + size - 1) {
    return recursion(N / 2, nowX, nowY, x1, y1, x1 + size - 1, y1 + size - 1, start);
  }

  if(nowX >= x1 + size && nowY >= y1 && nowX <= x2 && nowY <= y1 + size - 1) {
    return recursion(N / 2, nowX, nowY, x1 + size, y1, x2, y1 + size - 1, start + size * size);
  }

  if(nowX >= x1 && nowY >= y1 + size && nowX <= x1 + size - 1 && nowY <= y2) {
    return recursion(N / 2, nowX, nowY, x1, y1 + size, x1 + size - 1, y2, start + 2 * size * size);
  }

  if(nowX >= x1 + size && nowY >= y1 + size && nowX <= x2 && nowY <= y2) {
    return recursion(N / 2, nowX, nowY, x1 + size, y1 + size, x2, y2, start + 3 * size * size);
  }

}

int main() {
  int N, r, c;
  scanf("%d %d %d", &N, &r, &c);

  // for(int y = 0; y < pow(2, N); y++) {
  //   for(int x = 0; x < pow(2, N); x++) {
  //     printf("%*d ", 3, recursion(pow(2, N), x, y, 0, 0, pow(2, N) - 1, pow(2, N) - 1, 0));
  //   }
  //   printf("\n");
  // }
  printf("%d\n", recursion(pow(2, N), c, r, 0, 0, pow(2, N) - 1, pow(2, N) - 1, 0));
}