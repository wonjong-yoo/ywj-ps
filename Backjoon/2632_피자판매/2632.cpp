#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// vector<int> aSum(1000001, 0);
// vector<int> bSum(1000001, 0);

int aSum[1000001];
int bSum[1000001];


int main() {
  int need;
  cin >> need;
  
  int aMax, bMax;
  cin >> aMax >> bMax;
  vector<int> a(aMax);
  vector<int> b(bMax);
  
  for(int i = 0; i < aMax; i++) {
    cin >> a[i];
  }

  for(int i = 0; i < bMax; i++) {
    cin >> b[i];
  }

  

  for(int size = 1; size < aMax; size++) {
    int sum = 0;
    int left = 0;
    int right = left + size - 1;
    for(int i = left; i < size; i++) {
      int nowRight = i % aMax;
      sum += a[nowRight];
    }
    aSum[sum]++;
    for(int move = 0; move < aMax - 1; move++) {
      sum -= a[left];
      left = (left + 1) % aMax;
      right = (right + 1) % aMax;
      sum += a[right];
      aSum[sum]++;
    }
  }
  
  // 마지막으로 전체 더한거 하나
  int sum = 0;
  for(int i = 0 ; i < aMax; i++) {
    sum += a[i];
  }
  aSum[sum]++;

  for(int size = 1; size < bMax; size++) {
    int sum = 0;
    int left = 0;
    int right = left + size - 1;
    for(int i = left; i < size; i++) {
      int nowRight = i % bMax;
      sum += b[nowRight];
    }
    bSum[sum]++;

    for(int move = 0; move < bMax - 1; move++) {
      sum -= b[left];
      left = (left + 1) % bMax;
      right = (right + 1) % bMax;
      sum += b[right];
      bSum[sum]++;
    }
  }
  sum = 0;
  for(int i = 0 ; i < bMax; i++) {
    sum += b[i];
  }
  bSum[sum]++;
  
  // for(int i = 0; i <= 1000000; i++) {
  //   if(aSum[i] != 0) cout << "sum : " << i << ", count : " << aSum[i]<< endl;
  // }

  // for(int i = 0; i <= 1000000; i++) {
  //   if(bSum[i] != 0) cout << "sum : " << i << ", count : " << bSum[i] << endl;
  // }
  int answer = 0;

  for(int i = 0; i <= 1000000; i++) {
    if(aSum[i] == 0) continue;
    if(i >= need) break;

    int diff = need - i;
    

    answer += aSum[i] * bSum[diff];

  }
  // for(auto iter : aSum) {
  //   if(iter == 0) continue;
  //   if(iter.first >= need) break;
  //   int diff = need - iter.first;

  //   auto f = bSum.equal_range(diff);
  //   if(f.first == f.second) continue;
  //   // cout << "now A : " << iter.first << ", " << iter.second << " ==> diff : " << diff << " B : " << f.first->first << " , " << f.first->second << endl;
  //   // cout << "TEST : " << f.second->first << ", " << f.second->second << endl;
  //   // 없다면 같다.
    
    
  //   answer += iter.second * f.first->second;
  // }
  // A에서 모두 선택하는 경우
  // auto f = equal_range(aSum.begin(), aSum.end(), need);
  // if(f.first != f.second) answer += *f.first;

  // f = equal_range(bSum.begin(), bSum.end(), need);
  // if(f.first != f.second) answer += *f.first;

  answer += aSum[need];
  answer += bSum[need];

  cout << answer << endl;
}