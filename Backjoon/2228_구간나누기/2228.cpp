#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int recursion(int nowIndex, int count, int nowSum, vector<int>& arr, vector<vector<pair<int, int>>>& memo, vector<vector<int>>& memo2, int M) {
  if(nowIndex >= (int)arr.size()) {
    return INT32_MIN;
  }
  if(count == M) {
    memo2[nowIndex][count] = nowSum;
    return nowSum;
  }
  if(nowIndex >= 0 && memo2[nowIndex][count] != INT32_MIN) {
    //cout << "HIT" << endl;
    return memo2[nowIndex][count];
  }
  int maxResult = INT32_MIN;
  for(int left = nowIndex + 2; left < arr.size(); left++) {
    
    for(auto& iter : memo[left]) {
      int right = iter.first;
      int leftToRightSum = iter.second;
      //cout << "left : " << left << ", right : " << right << endl;
      int nowResult = recursion(right, count + 1, nowSum + leftToRightSum, arr, memo,memo2, M);
      //cout << "left : " << left << ", right : " << right << " : " << nowResult << endl;
      maxResult = max(maxResult, nowResult);
    }
  }
  if(maxResult == INT32_MIN && count != M) {
    return INT32_MIN;
  } else if(maxResult == INT32_MIN) {
    return nowSum;
  }

  if(nowIndex >= 0) memo2[nowIndex][count + 1] = maxResult;
  return maxResult;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> arr(N, 0);
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  
  vector<vector<pair<int, int>>> memo(N, vector<pair<int, int>>());
  vector<vector<int>> memo2(N, vector<int>(M, INT32_MIN));
  for(int left = 0; left < N; left++) {
    int sum = 0;
    int previous = INT32_MIN;
    for(int right = left; right < N /*&& right - left + 1 <= std::ceil(((double)N / 2))*/; right++) {
      if(previous >= arr[right]) break;
      sum += arr[right];
      memo[left].push_back({right, sum});
      
      previous = arr[right];
    }
  }
  cout << "COMPLETE" << endl;

  for(int i = 0; i < N; i++) {
    memo2[i][0] = arr[i];
  }

  cout << recursion(-2, 0, 0, arr, memo, memo2, M) << endl;

}