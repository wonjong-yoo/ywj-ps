#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INVALID_DIVDE = INT_MIN;

int getCipher(int n) {
  int i = 0;
  while (n != 0) {
    n /= 10;
    i++;
  }

  return i;
}

int get10Pow(int n) {
  int a = 1;
  while(n--) {
    a *= 10;
  }
  return a;
}

// divideNumber 는 1부터 시작
int calc(int n, int divideNumber) {
  int nowCipher = getCipher(n);
  int left = n / get10Pow((nowCipher - divideNumber));
  int right = n % get10Pow((nowCipher - divideNumber));

  int leftCipher = getCipher(left);
  int rightCipher = getCipher(right);
  if (leftCipher + rightCipher != nowCipher) {
    // 오른쪽 숫자가 일의 자리가 0일 때
    if (nowCipher - leftCipher == 1) {
      return left;
    }
    return INVALID_DIVDE;
  }

  return left + right;
}

int answerPlusNumber = INT_MAX;
int answerCallNumber = INT_MAX;

void recursion(int n, int callNumber) {
  if (n < 10) {
    if (answerCallNumber > callNumber) {
      answerPlusNumber = n;
      answerCallNumber = callNumber;
    }
    return;
  }
  int cipher = getCipher(n);

  for (int i = 1; i < cipher; i++) {
    int calced = calc(n, i);
    if (calced == INVALID_DIVDE) continue;
    recursion(calced, callNumber + 1);
  }
  
}

vector<int> solution(int n) {
  vector<int> answer;

  recursion(n, 0);

  answer.push_back(answerCallNumber);
  answer.push_back(answerPlusNumber);
  return answer;
}

int main() {
  vector<int> inputs = {73425, 10007, 9, 123456789, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (auto input: inputs) {
    vector<int> a = solution(input);
    cout << "result : " << a[0] << endl;
    cout << "call : " << a[1] << endl;
    answerCallNumber = INT_MAX;
    answerPlusNumber = INT_MAX;
  }
  
}