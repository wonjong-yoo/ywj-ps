#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10][10][10][10];
int board[10][10];
bool isVisited[10][10];
void isSqure(int x, int y, int size) {
  if(x + size >= 10 || y + size >= 10) return;
  
  int isZeroFind = false;
  for(int nowY = y, i = 0; i <= size; i++, nowY++) {
    for(int nowX = x, k = 0; k <= size; k++, nowX++) {
      if(board[nowY][nowX] == 0) {
        isZeroFind = true;
        break;
      }
    }
    if(isZeroFind) break;
  }
  if(isZeroFind == false) {
    arr[y][x][y + size][x + size] = 1;
  }
}

int answer = INT32_MAX;

int recursion(int x, int y, int one, int numOfOne, int papernum, vector<int>& paper ) {
  if(one == numOfOne) {
    answer = min(answer, papernum);
    return papernum;
  }
  if(one > numOfOne) {
    return INT32_MAX;
  }

  // int sum = numOfOne - one;
  // for(int i = 4; i >= 0; i--) {
  //   if(sum == 0) break;
  //   if(sum / ((i + 1) * (i + 1)) != 0) sum -= min((5 - paper[i]), sum / ((i + 1) * (i + 1))) * (i + 1) * (i + 1); 
  // }
  // if(sum != 0) return INT32_MAX;

  if(answer <= papernum) return INT32_MAX;

  for(int nowY = y; nowY < 10; nowY++) {
    for(int nowX = (nowY == y) ? x + 1 : 0; nowX < 10; nowX++) {
      if(isVisited[nowY][nowX]) continue;

      if(board[nowY][nowX] == 1) {
        for(int size = 4; size >= 0; size--) {
          if(nowY + size >= 10 || nowX + size >= 10) continue;
          if(arr[nowY][nowX][nowY + size][nowX + size]) {
          bool isOneFind = false;
          
          if(paper[size] == 5) continue;
          for(int vY = nowY; vY <= nowY + size; vY++) {
            for(int vX = nowX; vX <= nowX + size; vX++) {
              if(isVisited[vY][vX]) {
                isOneFind = true;

                for(int YY = vY; YY >= nowY; YY-- ) {
                  for(int XX = (vY == YY) ? vX - 1 : 0; XX >= nowX; XX--) {
                    isVisited[YY][XX] = false;
                  }
                }

                break;
              }
              isVisited[vY][vX] = true;
            }
            if(isOneFind) break;
          }
          if(isOneFind) continue;
            // for(int vY = nowY; vY <= nowY + size; vY++) {
            //   for(int vX = nowX; vX <= nowX + size; vX++) {
            //     isVisited[vY][vX] = true;
            //   }
            // }

            
          
            paper[size]++;
            //printf("sel : (%d, %d), (%d, %d), size : %d\n", nowX, nowY, nowX + size, nowY + size, size);
            int result = recursion(nowX, nowY, one + ((size + 1) * (size + 1)), numOfOne, papernum + 1, paper);
            paper[size]--;
            answer = min(result, answer);
            for(int vY = nowY; vY <= nowY + size; vY++) {
              for(int vX = nowX; vX <= nowX + size; vX++) {
                isVisited[vY][vX] = false;
              }
            }
            if(result != INT32_MAX) break;
          }
          

        }
      }


    }
  }

  return answer;
}

int main() {
  int numOfOne = 0;

  for(int y = 0; y < 10; y++) {
    for(int x = 0; x < 10; x++) {
      cin >> board[y][x];
    }
  }

  for(int y = 0; y < 10; y++) {
    for(int x = 0; x < 10; x++) {
      if(board[y][x] == 1) numOfOne++;

      for(int size = 0; size < 5; size++) {
        isSqure(x, y, size);
      }
    }
  }
  vector<int> paper(5, 0);
  int result = recursion(0, 0, 0, numOfOne, 0, paper);
  if(result == INT32_MAX) cout << "-1\n";
  else cout << result << endl;
}