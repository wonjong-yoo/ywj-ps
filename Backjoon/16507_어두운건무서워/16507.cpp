#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int R, C, Q;
  cin >> R >> C >> Q;

  vector<vector<int>> board(R + 1, vector<int>(C + 1, 0));
  vector<vector<int>> memo(R + 1,vector<int>(C + 1, 0));

  for(int y = 1; y <= R; y++) {
    for(int x = 1; x <= C; x++) {
      cin >> board[y][x];    
    }
  }

  for(int r = 1; r <= R; r++) {
    for(int c = 1; c <= C; c++) {
      memo[r][c] = memo[r][c - 1] + memo[r - 1][c] - memo[r - 1][c - 1] + board[r][c];
    }
  }

  for(int q = 0; q < Q; q++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << (memo[r2][c2] - memo[r1 - 1][c2] - memo[r2][c1 - 1] + memo[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << "\n";
  }
}