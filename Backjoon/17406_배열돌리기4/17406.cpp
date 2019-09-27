#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

void printBoard(vector<vector<int>>& board) {
  for(int y = 1; y < board.size(); y++) {
    for(int x = 1; x < board[0].size(); x++) {
      cout << board[y][x] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void rotateBoard(vector<vector<int>>& board, int r, int c, int s) {


  for(int size = 1; size <= s; size++) {
    int leftY = r - size;
    int leftX = c - size;

    int rightY = r + size;
    int rightX = c + size;
    int corner[] = {board[leftY][leftX], board[leftY][rightX], board[rightY][leftX], board[rightY][rightX]};
    
    int a = board[leftY][leftX];
    int b = board[leftY][leftX + 1];
    for(int x = leftX + 1; x <= rightX; x++) {
      b = board[leftY][x];
      board[leftY][x] = a;
      a = b;
    }

    a = corner[1];
    b = board[leftY + 1][rightX];
    for(int y = leftY + 1; y <= rightY; y++) {
      b = board[y][rightX];
      board[y][rightX] = a;
      a = b;
    }

    a = corner[3];
    b = board[rightY][rightX - 1];
    for(int x = rightX - 1; x >= leftX; x--) {
      b = board[rightY][x];
      board[rightY][x] = a;
      a = b;
      

      
    }

    a = corner[2];
    b = board[rightY - 1][leftX];
    for(int y = rightY - 1; y >= leftY; y--) {
      b = board[y][leftX];
      board[y][leftX] = a;
      a = b;
      
      
    
    }

  }
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  
  vector<vector<int>> board(N + 1, vector<int>(M + 1, -1));

  for(int y = 1; y <= N; y++) {
    for(int x = 1; x <= M; x++) {
      cin >> board[y][x];
    }
  }

  vector<tuple<int, int, int>> moveInfo;
  vector<int> moveOrder;
  for(int i = 0; i < K; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    moveInfo.push_back({r, c, s});
    moveOrder.push_back(i);
  }
  
  sort(moveOrder.begin(), moveOrder.end());
  int answer = INT32_MAX;
  do {
    vector<vector<int>> nowBoard;
    nowBoard = board;
    for(int i = 0; i < moveOrder.size(); i++) {
      tuple<int, int, int> nowOrder = moveInfo[moveOrder[i]];
      int r = get<0>(nowOrder);
      int c = get<1>(nowOrder);
      int s = get<2>(nowOrder);
      rotateBoard(nowBoard, r, c, s);
    }

    for(int y = 1; y < nowBoard.size(); y++) {
      int sum = 0;
      for(int x = 1; x < nowBoard[0].size(); x++) {
        sum += nowBoard[y][x];
      }
      answer = min(answer, sum);
    }
  } while(next_permutation(moveOrder.begin(), moveOrder.end()));
  cout << answer << "\n";
}