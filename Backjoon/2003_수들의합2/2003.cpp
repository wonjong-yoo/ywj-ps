#include <iostream>
#include <vector>

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

  int sum = input[0];
  int answer = 0;
  while(right < N) {
    //cout << "left : " << left << ", right : " << right << " sum : " << sum << endl;
    if(sum == M) {
      //cout << "HIT" << endl;
      answer++;
      right++;
      sum += input[right];
    } else if(sum > M) {
      sum -= input[left];
      // if(left == right) {
      //   left++;
      //   right++;
      //   sum += input[right];
      // } else {
      //   left++;
      // }
      left++;
      //sum += input[left];
    } else {
      right++;
      sum += input[right];
    }


  }

  cout << answer << endl;
}