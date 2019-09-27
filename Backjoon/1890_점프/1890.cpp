#include <iostream>
#include <vector>

using namespace std;

long long recursion(int y, int x, vector<vector<int>>& board, vector<vector<long long>>& dp) {
  if(y < 0 || x < 0 || y >= board.size() || x >= board.size()) {
    return 0;
  }

  if(dp[y][x] != 0) return dp[y][x];

  if(y == 0 && x == 0) {
    return 1;
  }
  
  long long answer = 0;
  for(int i = 1; y - i >= 0; i++) {
    if(board[y - i][x] == i) {
      long long temp = recursion(y - i, x, board, dp);
      if(temp != 0) {
        answer += temp;
      }
    }
  }

  for(int i = 1; x - i >= 0; i++) {
    if(board[y][x - i] == i) {
      long long temp = recursion(y, x - i, board, dp);
      if(temp != 0) {
        answer += temp;
      }
    }
  }

  dp[y][x] = answer;
  return answer;

}

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> board(N, vector<int>(N, 0));
  vector<vector<long long>> dp(N, vector<long long>(N, 0));

  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  cout << recursion(N - 1, N - 1, board, dp);
}