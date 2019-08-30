#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int check(vector<int>& lines, int divisor, int N) {
  int cnt = 0;
  for(int i = 0; i < lines.size(); i++) {
    cnt += lines[i] / divisor;
  }
  return cnt >= N;
}

int main() {
  int K, N;
  cin >> K >> N;

  vector<int> existLine;
  for(int i = 0; i < K; i++) {
    int temp;
    cin >> temp;
    existLine.push_back(temp);
  }
  
  long long ans = 0;
  long long l = 1;
  long long r = *max_element(existLine.begin(), existLine.end());

  while(l <= r) {
    //cout << "l : " << l << ", r : " << r << endl;
    long long mid = (l + r) / 2; 
    if(check(existLine, mid, N)) {
      if(ans < mid) {
        ans = mid;
      }
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << ans << endl;


}