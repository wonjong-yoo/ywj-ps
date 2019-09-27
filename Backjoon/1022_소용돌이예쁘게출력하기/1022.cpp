#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>


using namespace std;

int main() {
  int r1, c1, r2, c2;
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

  int rowSize = abs(r2 - r1) + 1;
  int colSize = abs(c2 - c1) + 1;
  vector<vector<int>> arr(rowSize, vector<int>(colSize, 0));

  // 왼쪽부터
  int origin = 1;
  int leftOrigin = 6;
  int leftColumn = -1;
  for(int size = 1; leftColumn >= c1; size++, leftColumn--) {
    // 위에서 부터 아래쪽으로 커지는 방향이라면

    for(int row = -size; row <= size; row++) {
      int nowNum = leftOrigin + row;
      //printf("row : %d, col : %d -> row : %d, col : %d ==> %d\n", row, leftColumn, row - r1, leftColumn - c1, nowNum);
      if(!(row <= r2 && row >= r1) || !(leftColumn <= c2 && leftColumn >= c1)) {
        continue;
      }
      
      arr.at(row - r1).at(leftColumn - c1) = nowNum;
    }
    leftOrigin += (8 * size)+ 5;
  }

  // 오른쪽
  int rightOrigin = 2;
  int rightColumn = 1;
  for(int size = 1; rightColumn <= c2; size++, rightColumn++) {
    
    for(int row = size - 1; row >= -size; row--) {
      int nowNum = rightOrigin - row;
      if(!(row <= r2 && row >= r1) || !(rightColumn <= c2 && rightColumn >= c1)) {
        continue;
      }
      arr.at(row - r1).at(rightColumn - c1) = nowNum;
    }
    rightOrigin += (8 * size) + 1;
  }

  // 아래쪽
  int bottomOrigin = 8;
  int bottomRow = 1;
  for(int size = 1; bottomRow <= r2; size++, bottomRow++) {
    
    for(int col = -size; col <= size; col++) {
      int nowNum = bottomOrigin + col;
      if(!(col <= c2 && col >= c1) || !(bottomRow <= r2 && bottomRow >= r1)) {
        continue;
      }
      arr.at(bottomRow - r1).at(col -c1) = nowNum;
    }

    bottomOrigin += (8 * (size + 1)) - 1;
  }

  int topOrigin = 4;
  int topRow = -1;
  for(int size = 1; topRow >= r1; size++, topRow--) {
    
    for(int col = size; col >= -size; col--) {
      int nowNum = topOrigin - col;
      if(!(col <= c2 && col >= c1) || !(topRow <= r2 && topRow >= r1)) {
        continue;
      }
      arr.at(topRow - r1).at(col - c1) = nowNum;
    }
    topOrigin += (8 * size) + 3;
  }
  
  if(c1 <= 0 && c2 >= 0 && r1 <= 0 && r2 >= 0) {
    arr[-r1][-c1] = 1;
  }

  int maxLength = 0;
  maxLength = max({std::ceil(std::log10(arr[0][0] + 1)), std::ceil(std::log10(arr[0][colSize - 1] + 1)), std::ceil(std::log10(arr[rowSize - 1][0] + 1)), std::ceil(std::log10(arr[rowSize - 1][colSize - 1] + 1))});
  for(int y = 0; y < arr.size(); y++) {
    for(int x = 0; x < arr[0].size(); x++) {
      //int nowLength = std::ceil(std::log10(arr[y][x] + 1));
      //printf("%d ", nowLength);
      //for(int i = nowLength; i <= maxLength; i++) printf(" ");
      printf("%*d ", maxLength, arr[y][x]);
    }
    printf("\n");
  }
}