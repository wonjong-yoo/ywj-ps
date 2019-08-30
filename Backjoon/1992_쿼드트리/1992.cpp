#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void DAQ(char **board, int ax, int ay, int bx, int by, int size) {
  if(ax > bx || ay > by) return;
  //2printf("\n(%d, %d) (%d, %d)\n", ax, ay, bx, by);
  if(size == 1) {
    char target2 = board[ay][ax];
    printf("%c", target2);
    return;
  }
  
  char target = board[ay][ax];
  for(int y = ay; y <= by; y++) {
    for(int x = ax; x <= bx; x++) {
      if(board[y][x] != target) {
        int newSize = size / 2;
        printf("(");
        DAQ(board, ax, ay, ax + newSize - 1, ay + newSize - 1, newSize);
        DAQ(board, ax + newSize, ay, bx, ay + newSize - 1, newSize);
        DAQ(board, ax, ay + newSize, ax + newSize - 1, by, newSize);
        DAQ(board, ax + newSize, ay + newSize, bx, by, newSize);
        printf(")");
        return;
      }    
    }
  }

  printf("%c", target);
}


int main() {
  int N;
  scanf("%d", &N);

  char** board = new char*[N];

  for(int i = 0; i < N; i++) {
    char *row = new char[N];
    scanf("%s", row);
    //printf("%s", row);
    board[i] = row;
  }

  DAQ(board, 0, 0, N-1, N-1, N);
  

}