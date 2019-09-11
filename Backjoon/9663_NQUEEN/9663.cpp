#include <iostream>
#include <vector>

using namespace std;

struct POINT {
  int x;
  int y;
  POINT(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

void printBoard(vector<POINT>& queens, int N) {
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++) {
      bool isFind = false;
      for(POINT& queen : queens) {
        if(queen.y == y && queen.x == x) isFind = true;
      }

      if(isFind) cout << "Q";
      else cout << "0";
      cout << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool canArrange(vector<POINT>& queens) {
  if(queens.size() == 1) return true;
  POINT target = queens.back();
  int x = target.x;
  int y = target.y;
  for(int i = 0; i < queens.size() - 1; i++) {
    
    // 상하
    if(x == queens[i].x) return false;
    if(y == queens[i].y) return false;

    int xdiff = abs(x - queens[i].x);
    int ydiff = abs(y - queens[i].y);
    //cout << "xdiff : " << xdiff << ", ydiff : " << ydiff << endl;
    if(xdiff == ydiff) return false;

  }

  return true;
}

int answer = 0;

void recursion(int y, int x, vector<POINT>& queens, int N) {
  // 넣을 수 없다면 끝낸다.
  if(!canArrange(queens)) {
    return;
  }

  if(queens.size() == N) {
    answer++;
   // printBoard(queens, N);
    return;
  }

  for(int nowX = 0; nowX < N; nowX++) {
    //cout << nowY << nowX << endl;
    if(nowX == x) continue;
    queens.push_back(POINT(nowX, y + 1));
    recursion(y + 1, nowX, queens, N);
    queens.pop_back();
  }
  // for(int nowY = y + 1; nowY < N; nowY++) {
  //   for(int nowX = (nowY == y ? x + 1 : 0); nowX < N; nowX++) {
  //     //cout << nowY << nowX << endl;
  //     recursion(nowY, nowX, queens, N);
  //   }
  // }
}

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> board(N, vector<int>(N, 0));
  vector<POINT> queens;
  for(int x = 0; x < N; x++) {
    
    queens.push_back(POINT(x, 0));
    recursion(0, x, queens, N);
    queens.pop_back();
  }
  

  cout << answer << endl;
}