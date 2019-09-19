#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<long long> histogram;
  
  histogram.reserve(100000);


  while(N) {
    memset(&histogram[0], -1 , sizeof(long long) * 100000);
    
    vector<long long> s;
    set<int> el;
    s.reserve(100000);

    int answer = 0;

    for(int i = 0; i < N; i++) {
      scanf("%d", &histogram[i]);
      el.insert(histogram[i]);
    }

    for(int i = 0; i < N; i++) {
      if(s.empty()) {
        s.push_back(histogram[i]);
        continue;
      }

      long long heightOfTop = s.back();
      if(histogram[i] >= heightOfTop) {
        s.push_back(histogram[i]);
      } else {
        // s는 오름차순 정렬이 된 상태이다.
        long long maxSize = 0;
        for(int k = s.size() - 1, num = 1; k >= 0; k--, num++) {
          long long nowSize = num * s[k];
          if(maxSize >= nowSize) {
            break;
          }
          maxSize = nowSize;
        }
        answer = max(answer, maxSize);
        s.clear();
      }
    }
    if(s.size() != 0) {
      long long maxSize = 0;
      for(int k = s.size() - 1, num = 1; k >= 0; k--, num++) {
        long long nowSize = num * s[k];
        if(maxSize >= nowSize) {
          break;
        }
        maxSize = nowSize;
      }
      answer = max(answer, maxSize);
    }

    // 작은 것부터 순서대로 생각해본다.
    for(const auto& iter = el.begin(); iter != el.end(); iter++) {
      int nowHeight = *iter;
      if(nowHeight * histogram.size() <= answer) 
    }
    
    printf("%d\n", answer);

    scanf("%d", &N);
  }
  
}