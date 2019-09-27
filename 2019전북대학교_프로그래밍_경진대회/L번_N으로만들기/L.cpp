#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

set<string> result;

void recursion(string& original, string now, int index, vector<bool>& isVisited, string order, int move) {
  
  if(original.length() == now.length()) {
    result.insert(order);
    
    //cout << order << endl;
    return;
  }
  
  if(index < 0 || index >= original.length()) return;
  


  if(isVisited[index]) return;

  if(move == 0) now += original[index];
  else if(move == 1) now.insert(now.begin(), original[index]);
  //cout << "index : " << index << endl;
  //cout << "order : " << order << endl;
  //cout << "now : " << now << endl;
  isVisited[index] = true;
  
  //현재 Visited중에서 가장 작은 인덱스오 가장 큰 인덱스
  int minv = INT32_MAX;
  int maxv = INT32_MIN;

  for(int i = 0; i < isVisited.size(); i++) {
    if(isVisited[i] == false) continue;
    minv = min(minv, i);
    maxv = max(maxv, i);
  }
  recursion(original, now, minv - 1,isVisited, order + now, 1);
  recursion(original, now, maxv + 1,isVisited, order + now, 0);

  isVisited[index] = false;
  
  return;


}

int main() {
  string input;
  cin >> input;

  vector<bool> isVisited(input.length(), false);

  for(int i = 0; i < input.size(); i++) {
    recursion(input, "", i, isVisited, "", 0);
  }

  // queue<tuple<string, string, int>> q;
  // for(int i = 0; i < input.length(); i++) {
  //   q.push({input.substr(i, 1), input.substr(i, 1), i + 1});
  // }

  // while(!q.empty()) {
  //   tuple<string, string, int> t = q.front();
  //   q.pop();
  //   string now = get<0>(t);
  //   string order = get<1>(t);
  //   int visited = get<2>(t);
    
  //   if(now.length() == input.length()) {
  //     cout << order << endl;
  //     result.insert(order);
  //     continue;
  //   }

  //   int minv = INT32_MAX;
  //   int maxv = INT32_MIN;
    
  //   for(int i = 1, k = 1; i <= input.length(); i++, k *= 2) {
  //     if(visited & k) {
  //       minv = min(minv, i);
  //       maxv = max(maxv, i);
  //     } else continue;
  //   }

  //   if(minv >= 2) {
  //     string a = now.append(0, input[minv - 2]);
  //     q.push({a, order + a, visited | (int)pow(2, minv)});
  //   }
  //   if(maxv + 1 <= input.length()) {
  //     q.push({now + input[maxv - 1], order + now, visited | (int)pow(2, maxv + 1)});
  //   }

  // }
  cout << result.size() << "\n";
  
}