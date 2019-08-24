#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Reserve {
  public:
    int startTime;
    int endTime;
    Reserve(int startTime, int endTime) {
      this->startTime = startTime;
      this->endTime = endTime;
    }
};

vector<Reserve> reserves;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int tempStartTime, tempEndTime;
    cin >> tempStartTime >> tempEndTime;
    reserves.push_back(Reserve(tempStartTime, tempEndTime));
  }

  // 끝나는 시간으로 오름차순 정렬
  std::sort(reserves.begin(), reserves.end(), [](const Reserve &left, const Reserve &right) {
    if(left.endTime == right.endTime) {
      return left.startTime < right.startTime;
    } else {
      return left.endTime < right.endTime;
    }
    
  });

  int nowTime = 0;
  int answer = 0;
  
  for(int i = 0; i < n; i++) {
    Reserve nowReserve = reserves[i];
    if(nowTime <= nowReserve.startTime) {
      nowTime = nowReserve.endTime;
      answer++;
    }
  }

  cout << answer << endl;


}