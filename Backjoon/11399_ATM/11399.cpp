#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> queue(N);

  for(int i = 0; i < N; i++) {
    cin >> queue[i];
  }

  std::sort(queue.begin(), queue.end());

  int answer = 0;
  int tempSum = 0;

  for(int i = 0; i < N; i++) {
    tempSum += queue[i];
    answer += tempSum;
  }

  cout << answer << endl;
  
}