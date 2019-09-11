#include <vector>
#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

class Point {
  public:
    int x;
    int y;
    Point(int x, int y) {
      this->x = x;
      this->y = y;
    }
};


vector<vector<int>> board(9, vector<int>(9, -1));


void printBoard() {
  cout << endl;
  for(int y = 0; y < 9; y++) {
    for(int x = 0; x < 9; x++) {
      cout << board[y][x] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

vector<int> findPossibleNumber(int x, int y) {
  vector<int> impossibleNumbers(10, 0);
  for(int nowX = 0; nowX < 9; nowX++) {
    impossibleNumbers[board[y][nowX]] = 1;
    impossibleNumbers[board[nowX][x]] = 1;
  }

  //사각형 영역에서 검사
  for(int nowY = y - (y % 3); nowY < y - (y % 3) + 3; nowY++) {
    for(int nowX = x - (x % 3); nowX < x - (x % 3) + 3; nowX++) {
      impossibleNumbers[board[nowY][nowX]] = 1;
    }
  }
  vector<int> returnValue;
  for(int i = 1; i < 10; i++) {
    if(impossibleNumbers[i] == 0) {
      returnValue.push_back(i);
    }
  }
  return returnValue;
}

void recursion(int blankIndex, vector<Point>& blanks) {
  if(blankIndex == blanks.size()) {
    printBoard();
    exit(0);
  }
  int x = blanks[blankIndex].x;
  int y = blanks[blankIndex].y;

  vector<int> possibleNumbers = findPossibleNumber(x, y);
  // cout << "x : " << x << ", y : " << y << " possible Number is " << endl;
  // for(int i = 0; i < possibleNumbers.size(); i++) {
  //   cout << possibleNumbers[i] << " ";
  // }
  // cout << endl;
  for(int i = 0; i < possibleNumbers.size(); i++) {
    board[y][x] = possibleNumbers[i];
    //printBoard();
    recursion(blankIndex + 1, blanks);
  }
  board[y][x] = 0;
}

int main() {
  vector<Point> blanks;

  for(int y = 0; y < 9; y++) {
    for(int x = 0; x < 9; x++) {
      cin >> board[y][x];
      if(board[y][x] == 0) {
        blanks.push_back(Point(x, y));
      }
    }
  }

  recursion(0, blanks);
}