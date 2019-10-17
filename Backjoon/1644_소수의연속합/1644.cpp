#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
  int N = 4000000;
  vector<int> arr(N + 1, 1);

  for(int i = 2; i <= sqrt(N); i++) {
    if(arr[i] == 0) {
      continue;
    } 
    for(int j = i + i; j <= N; j += i) {
      arr[j] = 0;
    }
  }
  
  vector<int> sosu;
  sosu.reserve(N);
  //sosu.push_back(1);
  sosu.push_back(2);

  for(int i = 3; i <= N; i += 2) {
    if(arr[i] == 1) {
      sosu.push_back(i);
    }
  }

  // for(int i = 0; i < 10; i++) {
  //   cout << sosu[i] << " ";
  // }
  sosu.push_back(0);

  int M;
  cin >> M;

  int left = 0;
  int right = 0;
  int sum = sosu[left];
  int answer = 0;

  while(right < N) {
    if(sum == M) {
      answer++;
      right++;
      sum += sosu[right];
    } else if(sum > M) {
      sum -= sosu[left];
      left++;
    } else {
      right++;
      sum += sosu[right];
    }
  }

  cout << answer << endl;
}