#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> input(N + 1, 0);
  
  for(int i = 0; i < N; i++) {
    cin >> input[i];
  }

  int left = 0;
  int right = 0;
  int sum = input[left];
  int answer = INT_MAX;
  while(right < N) {
    if(sum == M) {
      answer = min(answer, right - left + 1);
      right++;
      sum += input[right];
    } else if(sum > M) {
      answer = min(answer, right - left + 1);
      sum -= input[left];
      left++;
    } else {
      right++;
      sum += input[right];
    }
  }

  if(answer == INT_MAX) cout << "0\n";
  else cout << answer << "\n";
}