#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;



bool isPrime(int num) {
  bool prime = true;
  for(int i = 2; i <= sqrt(num); i++) {
    if(num % i == 0) {
      prime = false;
      break;
    }
  }
  return prime;
}

int main() {
  int T;
  cin >> T;
  for(int testcase = 0; testcase < T; testcase++) {
    string fromString, toString;
    cin >> fromString >> toString;
    int fromNumber = stoi(fromString);
    int toNumber = stoi(toString);
    
    queue<tuple<string, int>> tasks;
    tasks.push(make_tuple(fromString, 0));

    int answer = __INT_MAX__;
    vector<int> dist(10000, 0);
    vector<int> isVisit(10000, 0);
    while(!tasks.empty()) {
      
      tuple<string, int> task = tasks.front();
      tasks.pop();

      int nowNum = stoi(std::get<0>(task));
      int sum = std::get<1>(task);
      
      //cout << "now : " << nowNum << endl;
      if(nowNum < 1000 || nowNum > 9999) continue;
      if(!isPrime(nowNum)) continue;

      

      if(nowNum == toNumber) {
        answer = min(answer, sum);
        continue;
      }

      if(isVisit[nowNum] == 1 && dist[nowNum] < sum) {
        continue;
      }

      isVisit[nowNum] = 1;
      dist[nowNum] = sum;
      
      for(int i = 0; i < 4; i++) {
        string nowString = std::get<0>(task);
        char temp = nowString[i];
        for(char k = '0'; k <= '9'; k++) {
          if(temp == k) continue;
          string nextString = std::get<0>(task);
          nextString[i] = k;
          tasks.push(make_tuple(nextString, sum + 1));
        }
      }

      
    }
    cout << answer << endl;
  }
}