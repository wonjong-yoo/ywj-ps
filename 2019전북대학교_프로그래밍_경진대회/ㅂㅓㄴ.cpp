#include <vector>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int comb[101][101] = {};

int createcomb() {
  comb[1][0] = 1;
  comb[1][1] = 1;
  for(int i = 2; i < 101; i++) {
    comb[i][0] = 1;
    for(int j = 1; j <= 101; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }
}
int main() {
  int n = 2;
  int m = 2;
  int k = 5;
  createcomb();
  string answer = "";
  int nowCount = 0;
  int allNum = n + m;
  while(n != 0 && m != 0) {
    cout << comb[allNum - 1][m] << endl;
    int nowComb = 0;
    if(allNum - 1 >= 0 && m >= 0) nowComb = comb[allNum - 1][m];
    if(nowCount + nowComb >= k) {
      answer += '(';
      n--; allNum--;
    } else {
      nowCount += nowComb;
      answer += ')';
      m--; allNum--;
    }
    
    cout << answer << endl;
  }

  cout << "N : " << n << ", " << "M : " << m << endl;

  while(n != 0) {
    answer += '(';
    n--;
  }
  while(m != 0) {
    answer += ')';
    m--;
  }
  cout << answer << endl;
}