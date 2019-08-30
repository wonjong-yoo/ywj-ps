#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(vector<long long>&trees, long long height, int M) {
  long long sum = 0;
  for(int i = 0; i < trees.size(); i++) {
    sum += max(trees[i] - height, (long long)0);
  }

  return sum >= M;
}

int main() {
  int N;
  long long M;
  cin >> N >> M;

  vector<long long> trees;
  for(int i = 0; i < N; i++) {
    long long temp;
    cin >> temp;
    trees.push_back(temp);
  }

  long long left = 0;
  long long right = *max_element(trees.begin(), trees.end());
  
  long long answer = 0;
  while(left <= right) {
    long long mid = (left + right) / 2;
    if(check(trees, mid, M)) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << answer << endl;
}