#include <vector>
#include <iostream>

using namespace std;

int recursion(vector<int>& inputs, int nowSum, int nowIndex, int targetSum) {
  if(nowIndex >= inputs.size()) return -1;
  int sum = 0;
  if(nowSum == targetSum) sum += 1;
  for(int i = nowIndex + 1; i < inputs.size(); i++) {
    int result = recursion(inputs, nowSum + inputs[i], i, targetSum);
    if(result != -1) sum += result;
  }
  return sum;
}

int main() {
  int N, targetSum;
  cin >> N >> targetSum;

  vector<int> inputs(N);
  for(int i = 0; i < N; i++) {
    cin >> inputs[i];
  }

  int sum = 0;
  for(int i = 0; i < inputs.size(); i++) {
    int result = recursion(inputs, inputs[i], i, targetSum);
    if(result != -1) sum += result;
  }

  cout << sum << endl;
}

// 5 + (4 + 3 + 2 + 1) + (3 + 2 + 1) + (2 + 1) + 1