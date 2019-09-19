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
    //s.reserve(100000);

    long long answer = 0;

    for(int i = 0; i < N; i++) {
      scanf("%lld", &histogram[i]);
    }

    for(int i = 0; i < N; i++) {

      while(!s.empty() && histogram[s.back()] > histogram[i]) {
        long long height = histogram[s.back()];
        s.pop_back();
        long long width = i;
        if (!s.empty()) {
            width = (i - s.back() - 1);
        }
        answer = max(answer, height * width);
        
      }
      
      s.push_back(i);
    }
    
    while(!s.empty()) {
      long long height = histogram[s.back()];
      s.pop_back();
      long long width = N;
      if (!s.empty()) {
          width = (N - s.back() - 1);
      }
      answer = max(answer, height * width);
      
    }

    printf("%lld\n", answer);

    scanf("%d", &N);
  }
  
}