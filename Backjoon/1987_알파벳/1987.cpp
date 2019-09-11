#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int answer = 0;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int R, C;

void recursion(int x, int y, vector<bool>& passed, vector<string>& board, int cnt) {

  if(x < 0 || y < 0 || y >= R || x >= C) return;
  if(passed[board[y][x] - 'A'] == true) {
    return;
  }
  //if(check[y][x] > passed.size()) return;
  passed[board[y][x] - 'A'] = true;

  answer = max(cnt, answer);
  //check[y][x] = passed.size();

  // cout << "x : " << x << ", y : " << y << ", board[y][x] : " << board[y][x] << endl;
  // for(const char& iter : passed) {
  //   cout << iter;
  // }
  // cout << endl;

  for(int i = 0; i < 4; i++) {
    int newY = y + dy[i];
    int newX = x + dx[i];
    recursion(newX, newY, passed, board, cnt + 1);
  }
  passed[board[y][x] - 'A'] = false;
}

int main() {
  cin >> R >> C;

  vector<string> board(R, "");

  for(int y = 0; y < R; y++) {
    cin >> board[y];
  }

  vector<bool> passed(49, false);
  recursion(0, 0, passed, board, 1);


  cout << answer << endl;
}