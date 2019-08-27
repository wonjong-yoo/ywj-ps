#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  int rest = 0;
  int maxTeam = floor((double)N / 2);
  
  

  if(maxTeam > M) {
    rest += N - (M * 2);
    maxTeam = M;
  } else if(maxTeam < M) {
    rest += N - (maxTeam * 2);
    rest += M - maxTeam;
  }
  
  int answer = maxTeam;
  //인턴십에 참여해야할 학생이 남은 학생보다 많은 경우
  if(K > rest) {
    rest = K - rest;
    answer = floor((double)((maxTeam * 3) - rest) / 3);
  }

  cout << answer << endl;
}