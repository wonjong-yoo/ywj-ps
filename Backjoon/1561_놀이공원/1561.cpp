#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//  - 문제를 변형해서 N번째 학생이 타는 놀이기구의 번호를 푸는 문제로 변형할 수 있다.
//  - N 분까지 몇명의 학생이 탔는지는 쉽게 구할 수 있다. 8분까지는 5 + 8/1 + 8/2 + 8/3 + 8/4 + 8/5 = 22
//  - 8분에 탄 학생의수도 구할 수 있다. (8분은 3명(8 % 1 == 0, 8%2 == 0, 8%4 == 0)
bool check(vector<int>& plays, int target, int student) {
  // N분까지 탄 학생의 수
  
  int sum = plays.size();
  for(int i = 0; i < plays.size(); i++) {
    sum += target / plays[i];
  }

  for(int i = plays.size() - 1; i >= 0; i--) {

    if(target % plays[i] == 0) {
      sum --;
    }
  }

  sum++;

  return false;
}

int main() {
  long long N;
  int M;
  cin >> N >> M;

  vector<int> plays;
  for(int i = 0; i < M; i++) {
    int temp;
    cin >> temp;
    plays.push_back(temp);
  }

  if(N <= M) {
    cout << N << endl;
    return 0;
  }

  long long left = 0;
  long long right = 2000000000LL * 1000000LL;
  while(left <= right) {
    long long mid = (left + right) / 2;
    long long begin, end;
    begin = end = 0;
    end = M;
    
    for(int i = 0; i < plays.size(); i++) {
      end += mid / plays[i];
    }
    begin = end;
    for(int i = 0; i < plays.size(); i++) {
      if(mid % plays[i] == 0) {
        begin -= 1;
      }
    }
    
    begin += 1;

    if(N < begin) {
      right = mid - 1;
    } else if (N > end) {
      left = mid + 1;
    } else {
      for(int  i =0; i < plays.size(); i++) {
        if (mid % plays[i] == 0) {
          if(N == begin) {
            cout << i + 1 << endl;
            return 0;
          }
          begin += 1;
        }
      }
    }
  }
}