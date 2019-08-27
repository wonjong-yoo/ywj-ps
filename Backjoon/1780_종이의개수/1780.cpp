#include <iostream>
#include <vector>
#include <exception>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int zero = 0;
int one = 0;
int minusone = 0;

int recursion(vvi &board, int size, int x1, int y1, int x2, int y2) {
  //cout << "x1 : " << x1 << ", y1 : " << y1 << ", x2 : " << x2 << ", y2 : " << y2 << endl;
  //cout << "size : " << size << endl;
  // BaseCase
  int targetSymbol = board[y1][x1];
  if(size == 1) {
    //cout << "SIZE HIT!" << endl;
    if(targetSymbol == 0) zero++;
    else if(targetSymbol == 1) one++;
    else if(targetSymbol == -1) minusone++;
    else throw exception();
    return 0;
  }
  for(int h = y1; h <= y2; h++) {
    for(int w = x1; w <= x2; w++) {

      if(targetSymbol != board[h][w]) {
        int newX = x1;
        int newY = y1;
        int newSize = size / 3;
        for(int hi = 0; hi < 3; hi ++) {
          for(int wi = 0; wi < 3; wi++) {
            //cout << "-----------------" << endl;
            recursion(board, size / 3, newX + (hi * newSize) , newY + (wi * newSize), newX + (hi * newSize) +newSize - 1, newY + (wi * newSize) + newSize - 1);
          }
        }
        return 0;
      }

    }
  }

  if(targetSymbol == 0) zero++;
  else if(targetSymbol == 1) one++;
  else if(targetSymbol == -1) minusone++;
  else throw exception();
  //cout << "REAL HIT!" << endl;
  return 0;
}

int main() {
  int N;
  cin >> N;

  vvi board(N);
  for(int height = 0; height < N; height++) {
    vi row(N);
    for(int width = 0; width < N; width++) {
      cin >> row[width];
    }
    board[height] = row;
  }

  recursion(board, N, 0, 0, N - 1, N - 1);

  cout << minusone << endl << zero << endl << one << endl;
}