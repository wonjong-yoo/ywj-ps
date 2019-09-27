#include <vector>
#include <cstdio>

using namespace std;

bool isPalindrom(vector<int>& sequence, int left, int right) {
  int size = right - left + 1;
  for(int i = 0; i < size / 2; i++) {
    if(sequence[left + i] != sequence[right - i]) return false;
  }
  return true;
}

int recursion(vector<int>& sequence, vector<vector<int>>& dp, int left, int right) {
  if(dp[left][right] != -1) {
    return dp[left][right];
  }

  int size = right - left + 1;
  
  if(size <= 3) {
    return dp[left][right] = isPalindrom(sequence, left, right);
  }
  // 쪼개서 팰린드롬인지 확인한다.
  if(size % 2 == 0) {
    int l = recursion(sequence, dp, left, left + (size / 2) - 1);
    int r = recursion(sequence, dp, left + (size / 2), right);
    if(l != r) return dp[left][right] = 0;
    else return dp[left][right] = isPalindrom(sequence, left, right);
  } else {
    int l = recursion(sequence, dp, left, left + (size / 2) - 1);
    int r = recursion(sequence, dp, right - (size / 2) + 1, right);
    if(l != r) return dp[left][right] = 0;
    else return dp[left][right] = isPalindrom(sequence, left, right);
  }
  
}

int main() {
  int N;
  scanf("%d", &N);
  vector<int> sequence(N, 0);
  vector<vector<int>> dp(N, vector<int>(N, -1));

  for(int i = 0; i < N; i++) {
    scanf("%d", &sequence[i]);
    dp[i][i] = 1;
  }
  int M;
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    int left, right;
    scanf("%d %d", &left, &right);
    printf("%d\n", recursion(sequence, dp, left - 1, right - 1));
  }
}