#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<long long> person(N, 0);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &person[i]);
  }

  vector<pair<long long, long long>> s;
  long long answer = 0;
  bool isPoped = false;
  for(int i = 0; i < N; i++) {
    pair<long long, long long> p = {person[i], 1};
    while(!s.empty() && s.back().first <= person[i]) {
      // person[i] 보다 작은 것들을 모두 pop하고 1씩 더한다.
      //printf("A : %d, B : %d\n", s.back(), i);

      
      answer += (long long)s.back().second;
      if(s.back().first == person[i]) {
        p.second += s.back().second;
      }
      s.pop_back();
    }
    if(!s.empty()) {
      //printf("C : %d, D : %d\n", s.back(), i);
      answer += 1LL;
    }


    s.push_back(p);
    // 스택의 맨 처음 원소에 대해서 가시성을 확인한다.


    
  }

  printf("%lld", answer);
}