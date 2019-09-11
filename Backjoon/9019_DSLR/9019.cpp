#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <cstring>
using namespace std;

// int RotateLeft(int num) {
//   string numToString = to_string(num);
//   if(numToString.length() != 4) {
//     numToString.push_back('0');
//     return stoi(numToString);
//   } else {
//     char first = numToString[0];
//     for(int i = 0; i < 3; i++) {
//       numToString[i] = numToString[i + 1];
//     }
//     numToString[3] = first;

//     return stoi(numToString);
//   }
// }

// int RotateRight(int num) {
//   string numToString = to_string(num);
  
//   char last = numToString[numToString.length() - 1];
//   if(numToString.length() == 1 && last == '0') return 0;
  
//   numToString.pop_back();
//   if(numToString.length() == 0) return (last - 48) * 1000;
//   int returnValue = stoi(numToString);
//   returnValue += (last - 48) * 1000;
//   return returnValue;

// }
int visit[10001];
int dist[10001];
int from[10001];
char how[10001];
int main() {
  int T;
  scanf("%d", &T);
  for(int c = 0; c < T; c++) {
      int start, end;
      scanf("%d %d", &start, &end);
      // (현재 계산할 숫자, 몇번에 걸쳤는지, 이전 Action, 이전 숫자)
      queue<int> tasksQueue;
      tasksQueue.push(start);
      
      memset(visit, 0, sizeof(visit));
      memset(dist, 0, sizeof(dist));
      memset(from, 0, sizeof(from));
      memset(how, 0, sizeof(how));
      dist[start] = 0;
      from[start] = -1;
      visit[start] = 1;

      while(!tasksQueue.empty()) {
        int now = tasksQueue.front();
        tasksQueue.pop();

        



        int next = (now * 2) % 10000;
        if(visit[next] == 0) {
          tasksQueue.push(next);
          from[next] = now;
          dist[next] = dist[now] + 1;
          visit[next] = 1;
          how[next] = 'D';
        }
        next = now - 1;
        if(next == -1) next = 9999;
        if(visit[next] == 0) {
          tasksQueue.push(next);
          from[next] = now;
          dist[next] = dist[now] + 1;
          visit[next] = 1;
          how[next] = 'S';
        }
        next = (now%1000)*10 + now/1000;
        if(visit[next] == 0) {
          tasksQueue.push(next);
          from[next] = now;
          dist[next] = dist[now] + 1;
          visit[next] = 1;
          how[next] = 'L';
        }
        next = (now/10) + (now%10)*1000;
        if(visit[next] == 0) {
          tasksQueue.push(next);
          from[next] = now;
          dist[next] = dist[now] + 1;
          visit[next] = 1;
          how[next] = 'R';
        }
        
      }
      string ans = "";
      int index = end;
      while(index != start) {
        ans += how[index];
        index = from[index];
      }
      reverse(ans.begin(), ans.end());
      printf("%s", ans.c_str());
      printf("\n");
  }
}