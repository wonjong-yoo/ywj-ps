#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> input;
  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    input.push_back(temp);
  }

  std::sort(input.begin(), input.end());
  int answer = 0;
  do {
    int sum = 0;
    for(int i = 0; i < input.size() - 1; i++) {
      sum += abs(input[i] - input[i + 1]);
    }
    answer = max(answer, sum);
  } while(next_permutation(input.begin(), input.end()));

  cout << answer << endl;
}