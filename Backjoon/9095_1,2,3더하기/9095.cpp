#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(13, 0);

void recursion(int now, int nowsum, int target) {
  if(nowsum + now > target) return;
  
  
  if(nowsum != 0 && now + nowsum == target) {
    dp[target]++;
    return;
  }

  for(int i = 1; i <= 3; i++) {
    recursion(i, nowsum + now, target);
  }

}

int main() {
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  for(int i = 2; i <= 12; i++) {
    for(int k = 1; k <= 3; k++) {
      recursion(k, 0, i);
    }
  }
  int T;
  cin >> T;
  vector<int> test;
  for(int i = 0; i < T; i++) {
    int testcase;
    cin >> testcase;
    test.push_back(testcase);
    cout << dp[test[i]] << endl;
  }
}