
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

long long factorial(int n) {
  long long sum = 1;
  for(int i = 1; i <= n; i++) {
    sum = sum * i;
  }
  return sum;
}

int next(vector<int>& flag, int N) {
  int answer = 1;
  for(int i = 1; i <= N; i++) {
    if(flag[i] == 1) {
      N++;
      continue;
    }
    answer = i;
  }

  flag[answer] = 1;
  return answer;
}

vector<int> findPermutation(int N, long long k) {
  vector<int> array(N);
  vector<int> flag(21, 0);
  
  for(int i = 0; i < N; i++) {
    for(int j = 1; j <= N; j++) {
      if(flag[j] == 1) continue;
      if(factorial(N - i - 1) < k) {
        k -= factorial(N - i - 1);
      } else {
        array[i] = j;
        flag[j] = 1;
        break;
      }
    }
  }
  return array;
}

int main() {
  int N;
  int problem;
  long long k;
  scanf("%d", &N);
  scanf("%d", &problem);

  if(problem == 1) {
    scanf("%lld", &k);
    vector<int> answer = findPermutation(N, k);
    for(int i = 0; i < answer.size(); i++) {
      printf("%d ", answer[i]);
    }
  } else if(problem == 2) {
    vector<int> array(N);
    vector<int> c(N + 1, 0);
    long long answer = 0;
    for(int i = 0; i < N; i++) {
      int temp;
      scanf("%d", &temp);
      array[i] = temp;
    }
    for(int i = 0; i < array.size(); i++) {
        for(int j = 1; j < array[i]; j++) {
          if(c[j] == 0) {
            answer += factorial(N - i - 1);
          }
        }
        c[array[i]] = 1;
      }
    printf("%lld", answer + 1);
    
  }
}