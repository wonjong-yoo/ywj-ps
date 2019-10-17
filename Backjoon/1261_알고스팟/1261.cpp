#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

void printBoard(vector<string>& board) {
  for(int i = 0; i < board.size(); i++) {
    cout << board[i] << endl;
  }
}

void fillZero(queue<pair<int, int>>& q, vector<string> &board) {
  queue<pair<int, int>> tempQueue = q;
  while(!tempQueue.empty()) {
    int nowX = tempQueue.front().first;
    int nowY = tempQueue.front().second;
    tempQueue.pop();
    board[nowY][nowX] = '0';
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> board(M);
  vector<vector<bool>> isVisited(M + 1, vector<bool>(N + 1, false));
  for(int y = 0; y < M; y++) {
    cin >> board[y];
  }

  queue<pair<int, int>> q;
  
  queue<pair<int, int>> nextQ;

  q.push({0, 0});
  int answer = 0;
  while(1) {

    while(!q.empty()) {
      int nowX = q.front().first;
      int nowY = q.front().second;
      //cout << "y : " << nowY << ", nowX : " << nowX << endl;
      q.pop();
      
      if(nowX == N - 1 && nowY == M - 1) {
        cout << answer << endl;
        return 0;
      }

      if(nowX < 0 || nowY < 0 || nowX >= N || nowY >= M) continue;

      if(board[nowY][nowX] == '1') {
        //cout << "HIT y : " << nowY << ", nowX : " << nowX << endl;
        nextQ.push({nowX, nowY});
        continue;
      }

      if(isVisited[nowY][nowX]) continue;
      isVisited[nowY][nowX] = true;

      for(int i = 0; i < 4; i++) {
        q.push({nowX + dx[i], nowY + dy[i]});
      }
    }

    answer++;
    fillZero(nextQ, board);
    //printBoard(board);

    while(!nextQ.empty()) {
      int nowX = nextQ.front().first;
      int nowY = nextQ.front().second;
      
      nextQ.pop();
      
      if(nowX == N - 1 && nowY == M - 1) {
        cout << answer << endl;
        return 0;
      }

      if(nowX < 0 || nowY < 0 || nowX >= N || nowY >= M) continue;

      if(board[nowY][nowX] == '1') {
        q.push({nowX, nowY});
        continue;
      }

      if(isVisited[nowY][nowX]) continue;
      isVisited[nowY][nowX] = true;

      for(int i = 0; i < 4; i++) {
        nextQ.push({nowX + dx[i], nowY + dy[i]});
      }
    }
    answer++;
    fillZero(q, board);
    //printBoard(board);
  }
  
  
}