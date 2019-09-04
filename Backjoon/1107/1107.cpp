#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdlib.h>

#define ON 1
#define OFF 0

using namespace std;

int isPossible(int c, vector<int>& buttons) {
  int length = 0;
  if(c == 0) return buttons[0] == OFF ? 0 : 1;
  while(c > 0) {
    if(buttons[c % 10] == OFF) return 0;
    c /= 10;
    length++;
  }

  return length;
}

int main() {
  string N;
  
  int M;
  vector<int> buttons(10, ON);
  cin >> N;
  cin >> M;
  for(int i = 0; i < M; i++) {
    int temp;
    cin >> temp;
    buttons[temp] = OFF;
  }
  int NToInt = stoi(N);

  int answer = abs(NToInt - 100);
  for(int i = 0; i <= 1000000; i++) {
    int c = i;
    int length = isPossible(c, buttons);

    if(length) {
      int now = abs(NToInt - i) + length; 
      if(answer > now) answer = now;
    }
  }
  cout << answer << endl;
  // int fromOrigin = abs(NToInt - 100);

  // // 모든 자리에서 거리
  // int sum = 0;
  // for(int i = 0; i < N.length(); i++) {
  //   int position = N.length() - i - 1;
    
  //   for(int k = 0; k < 10; k++) {

  //     int basis = N[i] - 48;
  //     if(basis - k >= -1) {
  //       if(buttons[basis - k] == ON) {
  //         //cout << "선택 : " << basis - k << endl;
  //         if(!(i == 0 && basis - k == 0)) sum += (basis - k) * pow(10, position); 
  //         break;
  //       }
  //     }
  //     if(basis + k <= 9) {
  //       if(buttons[basis + k] == ON) {
  //         //cout << "선택 : " << basis + k << endl;
  //         if(i == 0 && basis - k == 0) continue;
  //         sum += (basis + k) * pow(10, position);
  //         break;
  //       }
  //     }
  //   }

  // }
  
  // int prevSum = 0;
  // // 한자리 이전에서 최대값
  // for(int i = 1; i <= N.length() - 1; i++) {
  //   int position = N.length() - i - 1;
  //   for(int k = 9; k >= 0; k--) {
  //     if(buttons[k] == ON) {
  //       prevSum += (k) * pow(10, position); 
  //       break;
  //     }
  //   }
  // }
  // if(prevSum == 0) prevSum = __INT_MAX__;
  // int fromPrevDigit = abs(prevSum - NToInt) + N.length() - 1;

  // int nextSum = 0;
  // // 한자리 이후에서 최대값
  // for(int i = 0; i <= N.length(); i++) {
  //   int position = N.length() - i;
  //   for(int k = 0; k < 10; k++) {
  //     if(k == 0 && i == 0) continue; // 첫번째 자리는 Skip
  //     if(buttons[k] == ON) {
  //       nextSum += (k) * pow(10, position); 
  //       break;
  //     }
  //   }
  // }
  // if(nextSum == 0) nextSum = __INT_MAX__;

  // int fromNextDigit = abs(nextSum - NToInt) + N.length() + 1;

  // int fromAllDigit = abs(sum - NToInt) + N.length();
  // cout << "origin : " << fromOrigin << endl;
  // cout << "all : " << fromAllDigit << endl;
  // cout << "prev : " << fromPrevDigit << endl;
  // cout << "next : " << fromNextDigit << endl;

  // cout << min(fromOrigin, min(fromAllDigit, min(fromPrevDigit, fromNextDigit))) << endl;
  // //int answer = min(formOrigin, sum);
  
}
