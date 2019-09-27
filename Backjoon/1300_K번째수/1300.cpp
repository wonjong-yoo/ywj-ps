#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

// 순서를 리턴한다.
long long s(long long target, long long N) {
  if(target == 1) return 1;
  if(target == 2) return 3;
  long long order = 0;

  for(long long i = 1; i <= N; i++) {
    order += (min(target, (long long)N * i) / i) * 2;
    order -= min((long long)(i - 1) * 2, (min(target, (long long)N * i) / i) * 2);
    if(i * i <= target) order--;
  }
  return order;
}

long long rs(long long k, long long N) {
  long long left = 1;
  long long right = min((long long)1000000000, N * N);
  map<long long, long long> memo;
  long long mid = (left + right) / 2;
  long long result = -1;
  //long long previous = s(mid, N);
  while(left <= right) {
    mid = (left + right) / 2;
    long long nowOrder = s(mid, N);
    cout << "mid : " << mid << " order : " << nowOrder << "\n";
    if(nowOrder < k) {
      left = mid + 1;
    } else {
      result = mid;
      right = mid - 1;
    } 
  }
  return result;
}

int main() {
  long long N, k;
  cin >> N >> k;
  if(k == 1) {
    cout << "1\n";
    return 0;
  }
  if(k == 2 || k == 3) {
    cout << "2\n";
    return 0;
  }


  cout << rs(k, N) << "\n";

  for(long long i = 1; i <= N * N; i++) {
    cout << "====" << i << "====" << endl;
    cout << "TTT : " << rs(i, N) << "\n";
  }

  // // mid와 가장 가까운 두 수를 찾는다.
  // long long leftMin = 0;
  // long long rightMax = __LONG_LONG_MAX__;

  // for(int i = 1; i < N; i++) {
  //   if(N * i < mid) continue;
  //   long long divisor_ceil = std::ceil(mid / i);
  //   long long divisor_floor = std::floor(mid / i);

  //   if(abs(leftMin - mid) >= abs(divisor_floor * i - mid)) {
  //     leftMin = divisor_floor * i;
  //   }
  //   if(abs(rightMax - mid) >= abs(divisor_ceil * i - mid)) {
  //     rightMax = divisor_ceil * i;
  //   }
  // }

  // cout << "min : " << leftMin << ", max : " << rightMax << endl;
  
}