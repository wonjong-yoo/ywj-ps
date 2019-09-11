#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <array>
#include <tuple>
#include <algorithm>

using namespace std;

int squeeze(int B, int C) {
  int value = 0;
  value += C;
  value += B * 1000;

  return value;
}

tuple<int, int, int> recover(int squeezeValue, int N) {
  int B = squeezeValue / 1000;
  int C = squeezeValue % 1000;
  int A = N - B - C;
  return make_tuple(A, B, C);
  
}

bool isAnswer(int nowA, int nowB, int nowC, int C) {
  return nowA == 0;
}

int main() {
  
  int A, B, C;
  cin >> A >> B >> C;

  map<int, int> dist;
  vector<int> answer;
  queue<int> tasks;

  tasks.push(squeeze(0, C));
  dist[squeeze(B, C)] = 1;
  
  while(!tasks.empty()) {
    int nowSqueeze = tasks.front();
    //cout << "squeeze : " << nowSqueeze << endl;
    tasks.pop();
    tuple<int, int, int> t = recover(nowSqueeze, C);
    int nowA = get<0>(t);
    int nowB = get<1>(t);
    int nowC = get<2>(t);
    //cout << "A : " << nowA << ", B : " << nowB << ", C : " << nowC << endl;
    if(dist.count(nowSqueeze)) {
      continue;
    }

    dist[nowSqueeze] = 1;
    if(isAnswer(nowA, nowB, nowC, C)) {
      answer.push_back(nowC);
    } 
    
    array<int, 3> nowArr = { nowA, nowB, nowC};
    array<int, 3> maxArr = { A, B, C};

    for(int fromIndex = 0; fromIndex < 3; fromIndex++) {
      for(int toIndex = 0; toIndex < 3; toIndex++) {
        if(fromIndex == toIndex) continue;

        int from = nowArr[fromIndex];
        int to = nowArr[toIndex];
        //int fromMax = maxArr[fromIndex];
        int toMax = maxArr[toIndex];
        
        int nextTo, nextFrom;
        if(from == 0 || to == toMax) continue;

        int diff = (toMax - to) - from;
        if(diff >= 0) {
          nextFrom = 0;
          nextTo = from + to;
        } else {
          //nextFrom = from + diff;
          nextFrom = -diff;
          nextTo = toMax;
        }

        int nextA = nowA, nextB = nowB, nextC = nowC;
        if(fromIndex == 0) nextA = nextFrom;
        else if(fromIndex == 1) nextB = nextFrom;
        else if(fromIndex == 2) nextC = nextFrom;

        if(toIndex == 0) nextA = nextTo;
        else if(toIndex == 1) nextB = nextTo;
        else if(toIndex == 2) nextC = nextTo;

        tasks.push(squeeze(nextB, nextC));
      }
    }
  }

  sort(answer.begin(), answer.end());
  for(int i = 0; i < answer.size(); i++) {
    cout << answer[i] << " ";
  }
  
}