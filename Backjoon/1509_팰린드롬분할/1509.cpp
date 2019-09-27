#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrom(vector<int>& sequence, int left, int right) {
  int size = right - left + 1;
  for(int i = 0; i < size / 2; i++) {
    if(sequence[left + i] != sequence[right - i]) return false;
  }
  return true;
}

void recursion(string& input, int left, int now, int& answer, vector<vector<int>>& dp, vector<int>& dp2) {
  if(dp2[left] < now) {
    return;
  }
  dp2[left] = now; 

  for(int right = input.length() - 1; right >= left; right--) {
    if(dp[left][right] == 1) {
      //cout << input.substr(left, right - left + 1) << endl;
      recursion(input, right + 1, now + 1, answer, dp, dp2);
    }
  }

  
}

int main() {
  string input;
  cin >> input;
  
  int inputLength = input.length();
  vector<vector<int>> dp(inputLength, vector<int>(inputLength, 0));
  vector<int> dp2(inputLength, __INT_MAX__);
  for(int i = 0; i < inputLength - 1; i++) {
    dp[i][i] = 1;
    if(input[i] == input[i + 1]) {
      dp[i][i + 1] = 1;
    }
  }
  dp[inputLength - 1][inputLength - 1] = 1;

  for(int size = 2; size < inputLength; size++) {
    for(int left = 0; left < inputLength - size; left++) {
      int right = left + size;
      if(input[left] == input[right] && dp[left + 1][right - 1] == 1) {
        dp[left][right] = 1;
      }
    }
  }


  int answer = __INT32_MAX__;
  //recursion(input, 0, 0, answer, dp, dp2);
  dp2[0] = 0;
    for (int i=0; i< inputLength; i++) {
        dp2[i] = -1;
        for (int j=0; j<=i; j++) {
            if (dp[j][i]) {
              int now;
              if(j == 0) now = 0;
              else now = dp2[j - 1]; 
              if (dp2[i] == -1 || dp2[i] > now+1) {
                  dp2[i] = now+1;
              }
            }
        }
    }
  cout << dp2[inputLength - 1] << endl;
}