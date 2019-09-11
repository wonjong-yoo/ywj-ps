#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int main() {
  string board;
  for(int i = 0; i < 9; i++) {
    int temp;
    cin >> temp;
    if(temp == 0) temp = 9;
    board.push_back(temp + 48);
  }

  map<string, int> dist;
  queue<string> q; 
  dist[board] = 0;
  q.push(board);
  while(!q.empty()) {
    string now = q.front();
    q.pop();

    int blank = now.find('9');
    int x = blank / 3;
    int y = blank % 3;

    for(int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      
      if(nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2) {
        string next = now;
        swap(next[x * 3 + y], next[nx*3 + ny]);

        if(dist.count(next) == 0) {
          dist[next] = dist[now] + 1;
          q.push(next);
        }
      }

    }
  }

  string final = "123456789";
  if(dist.count(final) != 0) {
    cout << dist[final] << endl;
  } else {
    cout << "-1" << endl;
  }

}