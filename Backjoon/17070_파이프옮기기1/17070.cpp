#include <vector>
#include <iostream>

using namespace std;

int recursion(int x1, int y1, int x2, int y2, int mode, vector<vector<int>>& board, vector<vector<bool>>& isVisited) {
  int N = board.size() - 1;
  if(x1 <= 0 || y1 <= 0 || x2 <= 0 || y2 <= 0 || x1 > N || y1 > N || x2 > N || y2 > N) return 0;
  if(mode == 1 || mode == 3) {
    if(board[y2][x2] == 1) return 0;
  } else if(mode == 2) {
    if(board[y2][x2] == 1 || board[y2 - 1][x2] == 1 || board[y2][x2 - 1] == 1) return 0;
  }

  
  if(y2 == N && x2 == N) {
    //cout << "END" << endl;
    return 1;
  }
  // 2번째 점을 방문 노드로 친다.
  isVisited[y2][x2] = true;

  //cout << mode << " : (" << x1 << ", " << y1 << "), (" <<  x2 << ", " << y2 << ")" << endl;
  int answer = 0;
  if(mode == 1) { // ㅡ
    answer += recursion(x2, y2, x2 + 1, y2, 1, board, isVisited);
    answer += recursion(x2, y2, x2 + 1, y2 + 1, 2, board, isVisited);
  } else if(mode == 2) { // 대각선
    answer += recursion(x2, y2, x2 + 1, y2, 1, board, isVisited);
    answer += recursion(x2, y2, x2, y2 + 1, 3, board, isVisited);
    answer += recursion(x2, y2, x2 + 1, y2 + 1, 2, board, isVisited);
  } else if(mode == 3) {
    answer += recursion(x2, y2, x2, y2 + 1, 3, board, isVisited);
    answer += recursion(x2, y2, x2 + 1, y2 + 1, 2, board, isVisited);
    
  }
  isVisited[y2][x2] = false;
  return answer;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> board(N + 1, vector<int>(N + 1, 1));

  for(int y = 1; y <= N; y++) {
    for(int x = 1; x <= N; x++) {
      cin >> board[y][x];
    }
  }

  vector<vector<bool>> isVisited(N + 1, vector<bool>(N + 1, false));

  cout << recursion(1, 1, 2, 1, 1, board, isVisited);
}