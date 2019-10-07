#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int d[10001][31];

int dfs(int nowTime, int maxTime, int switchNum, int maxSwitch, vector<int>& jadu) {
  // 현재 시간에서 안움직이고 얻을 수 있는 자두 개수
  // int nowAnswer = INT32_MIN;
  // nowAnswer = numOfJadu + dp[nowTime][maxTime - 1][nowJaduNamu];
  // nowAnswer = max(nowAnswer, dfs(numOfJadu + dp[nowTime][nowTime][nowJaduNamu], nowTime + 1, maxTime, nowJaduNamu, switchNum, maxSwitch, jadu, dp));
  // // 현재 시간에서 다른 나무로 스위치할 때 얻을 수 있는 자두 개수
  // if(switchNum < maxSwitch) {
  //   nowAnswer = max(nowAnswer, numOfJadu + dp[nowTime][maxTime - 1][!nowJaduNamu]);
  //   nowAnswer = max(nowAnswer, dfs(numOfJadu + dp[nowTime][nowTime][!nowJaduNamu], nowTime + 1, maxTime, !nowJaduNamu, switchNum + 1, maxSwitch, jadu, dp));
  // }

  if(nowTime == maxTime && switchNum <= maxSwitch) {
    return 0;
  }

  if(switchNum > maxSwitch) {
    return 0;
  }

  if(d[nowTime][switchNum] != -1) {
    return d[nowTime][switchNum];
  }
  
  int where = switchNum % 2 + 1;
  int& ans = d[nowTime][switchNum];
  ans = max(dfs(nowTime+1, maxTime, switchNum, maxSwitch, jadu), dfs(nowTime+1, maxTime, switchNum+1, maxSwitch, jadu)) + (where == jadu[nowTime] ? 1 : 0);
  return ans;
  
}

int main() {
  int T, W;
  cin >> T >> W;
  vector<int> jadu(T, 0);
  for(int i = 0; i < T; i++) {
    cin >> jadu[i];
  }
  
  memset(d,-1,sizeof(d));
  //cout << dfs(0, 0, T, 0, 0, W, jadu, dp) << endl;
  
  cout << max(dfs(0, T, 0, W, jadu), dfs(0, T, 1, W, jadu));

}