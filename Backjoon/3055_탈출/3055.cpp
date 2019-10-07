#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

// 1부터 시작
void floor(int nowTime, int R, int C, vector<vector<string>>& board) {
  for(int y = 0; y < R; y++) {
    for(int x = 0; x < C; x++) {
      if(board[nowTime - 1][y][x] == '*') {
        board[nowTime][y][x] = '*';
        for(int i = 0; i < 4; i++) {
          int nextY = y + dy[i];
          int nextX = x + dx[i];

          if(nextY < 0 || nextX < 0 || nextY >= R || nextX >= C) continue;
          if(board[nowTime - 1][nextY][nextX] != '.') continue;
          board[nowTime][nextY][nextX] = '*';
        }
      } else {
        if(board[nowTime][y][x] == '*') continue;
        else board[nowTime][y][x] = board[nowTime - 1][y][x];
      }
    }
  }
}

int bfs(pair<int, int>& biber, pair<int, int>& gosumdochi, vector<vector<string>>& board, int R, int C) {
  

  queue<tuple<int, int, int>> q;
  q.push({gosumdochi.first, gosumdochi.second, 0});
  
  vector<vector<bool>> isVisited(R, vector<bool>(C, false));

  int answer = INT32_MAX;

  while(!q.empty()) {
    tuple<int, int, int>& e = q.front();
    int nowX = get<0>(e);
    int nowY = get<1>(e);
    int nowTime = get<2>(e);
    q.pop();

    if(nowX < 0 || nowY < 0 || nowX >= C || nowY >= R) continue;

    if(isVisited[nowY][nowX]) continue;
    // 다음 시간을 봐서 물이 찼다면 continue;
    //if(board[nowTime + 1][nowY][nowX] == '*') continue;

    // 돌로 된 곳은 못감
    if(board[nowTime][nowY][nowX] == 'X') continue;

    if(board[nowTime][nowY][nowX] == 'D') {
      answer = min(answer, nowTime);
    }

    isVisited[nowY][nowX] = true;
    for(int i = 0; i < 4; i++) {
      // 다음 시간을 봐서 물이 찼다면 continue;
      if(nowX + dx[i] < 0 || nowY + dy[i] < 0 || nowX + dx[i] >= C || nowY + dy[i] >= R) continue;

      if(board[nowTime + 1][nowY + dy[i]][nowX + dx[i]] == '*') continue;
      else q.push({nowX + dx[i], nowY + dy[i], nowTime + 1});
    }
    

  }

  return answer;
}

int main() {
  int R, C;
  cin >> R >> C;
  int maxTime = R * C;
  vector<vector<string>> board(maxTime + 1, vector<string>(R, string(C, 'X')));

  pair<int, int> biber;
  pair<int, int> gosumdochi;

  for(int y = 0; y < R; y++) {
      cin >> board[0][y];

      for(int x = 0; x < C; x++) {
        if(board[0][y][x] == 'S') {
          gosumdochi = {x, y};
        }
        if(board[0][y][x] == 'D') {
          biber = {x, y};
        }
      }
  }

  for(int i = 1; i < maxTime; i++) {
    floor(i, R, C, board);
  }

  // for(int i = 0; i < maxTime; i++) {
  //   cout << endl << "=== " << i << " ===" << endl;
  //   for(int y = 0; y < R; y++) {
  //       cout << board[i][y] << endl;
  //   }
  //   cout << endl;
  // }
  
  int answer = bfs(biber, gosumdochi, board, R, C);
  if(answer == INT32_MAX) cout << "KAKTUS" << endl;
  else cout << answer << endl;
}