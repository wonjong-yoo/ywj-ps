#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>


#include <iostream>
using namespace std;

// bool check(vector<int> coordinators, int distance, int C) {
//   int numOfCoordinators = coordinators.size();
  
//   int beforeCoord = coordinators[0];
//   int nowIndex = 1;
//   for(int i = 1; i < C; i++) {
//     if(nowIndex >= numOfCoordinators) {
//       return false;
//     }
//     bool isHit = false;
//     for(; nowIndex < numOfCoordinators; nowIndex++) {
//       //printf("before : %d, now : %d\n", beforeCoord, coordinators[nowIndex]);
//       if(coordinators[nowIndex] - beforeCoord >= distance) {
//         //printf("HIT\n");
//         isHit = true;
//         beforeCoord = coordinators[nowIndex];
//         nowIndex++;
//         break;
//       }
//     }
//     if(!isHit && nowIndex >= numOfCoordinators) {
//       return false;
//     }
//   }
//   //printf("TRUE\n");
//   return true;
// }

bool check(vector<int> coordinators, int distance, int C) {
  int cnt = 1;
  int last = coordinators[0];
  for(int coord : coordinators) {
    if(coord - last >= distance) {
      cnt++;
      last = coord;
    }
    
  }

  return cnt >= C;
}

int main() {
  int N, C;
  scanf("%d %d", &N, &C);

  vector<int> coordinators;
  for(int i = 0; i < N; i++) {
    int temp;
    scanf("%d", &temp);
    coordinators.push_back(temp);
  }

  std::sort(coordinators.begin(), coordinators.end());

  int left = 1;
  int right = coordinators.back() - left;
  int answer = 0;
  while(left <= right) {
    //printf("left : %d, mid = %d, right : %d\n", left, (left + right) / 2, right);
    int mid = (left + right) / 2;
    if(check(coordinators, mid, C)) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }

  }

  printf("%d", answer);
}