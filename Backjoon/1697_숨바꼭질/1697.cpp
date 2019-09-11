#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <tuple>
using namespace std;

#define MINUS 0
#define PLUS 1
#define MULTI 2

vector<int> visit(200001, 0);
vector<int> dist(200001, 0);

int main() {
  int N, K;
  cin >> N >> K;
  queue<tuple<int, int, int>> taskQueue;
  taskQueue.push(make_tuple(MINUS, N, 0));
  taskQueue.push(make_tuple(PLUS, N, 0));
  taskQueue.push(make_tuple(MULTI, N, 0));
  int answer = __INT_MAX__;
  while(!taskQueue.empty()) {
    tuple<int, int, int> task = taskQueue.front();
    taskQueue.pop();
    int action = std::get<0>(task);
    int now = std::get<1>(task);
    int seconds = std::get<2>(task);
    
    //cout << "now : " << now << endl;
    if(seconds > answer) {
      continue;
    }

    if(now < 0) { 
      continue;
    }
    if(visit[now] && dist[now] < seconds) {
      continue;
    }
    visit[now] = 1;
    dist[now] = seconds;
    

    if(now == K) {
      answer = min(answer, seconds);
      continue;
    } else if (now > K) {
      answer = min(answer, seconds + abs(now - K));
      continue;
    }
    if (action == MINUS) {
      taskQueue.push(make_tuple(MULTI, now - 1, seconds + 1));
      taskQueue.push(make_tuple(MINUS, now - 1, seconds + 1));
      taskQueue.push(make_tuple(PLUS, now - 1, seconds + 1));
    } else if(action == PLUS) {
      taskQueue.push(make_tuple(MULTI, now + 1, seconds + 1));
      taskQueue.push(make_tuple(MINUS, now + 1, seconds + 1));
      taskQueue.push(make_tuple(PLUS, now + 1, seconds + 1));
    } else if(action == MULTI) {
      taskQueue.push(make_tuple(MULTI, now * 2, seconds + 1));
      taskQueue.push(make_tuple(MINUS, now * 2, seconds + 1));
      taskQueue.push(make_tuple(PLUS, now * 2, seconds + 1));
    }
  }

  cout << answer << endl;
  
}