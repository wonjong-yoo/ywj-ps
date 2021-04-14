#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string &S, vector<int> &C) {
  int answer = 0;
  for (auto i = 0; i + 1< S.size(); i++) {
    // 같은 문자열을 찾는다.
    if (S[i] == S[i + 1]) {
      int sum = C[i] + C[i + 1];
      int maxValue = std::max(C[i], C[i + 1]);
      int k = i  + 1;
      for (;k + 1< S.size(); k++) {
        if (S[k] == S[k + 1]) {
          sum += S[k + 1];
          maxValue = std::max(maxValue, S[k + 1]);
        } else {
          break;
        }
      }
      answer += sum - maxValue;
      i = k;
    }
    
  }
  return answer;
}

int main() {
  string input = "aaabbbb";
  vector<int> a = {1, 2, 3, 4, 5, 6};
  cout << solution(input, {1, 2, 3, 4, 5, 6});
}
