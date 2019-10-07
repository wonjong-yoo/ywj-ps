#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool isVisited[51][51] = { };

int recursion(int nowX, int nowY, int targetX, int targetY, int distance, vector<string>& board, bool isVisited[][51]) {
  if(nowX < 0 || nowY < 0 || nowY >= board.size() || nowX >= board[0].length()) return INT32_MAX;
  if(isVisited[nowY][nowX]) return INT32_MAX;
  if(board[nowY][nowX] == '#') return INT32_MAX;
  
  if(nowY == targetY && nowX == targetX) return distance;
  //cout << "nowX : " << nowX << ", nowY : " << nowY << " => " << distance << endl;
  //if(distance != 0 && (board[nowY][nowX] >= 48 && board[nowY][nowX] <= 48 + 9)) return INT32_MAX;
  //if(distance != 0 && (board[nowY][nowX] == 'S' || board[nowY][nowX] == 'E')) return INT32_MAX;

  isVisited[nowY][nowX] = true;
  int minV = INT32_MAX;
  for(int i = 0; i < 4; i++) {
    int result = recursion(nowX + dx[i], nowY + dy[i], targetX, targetY, distance + 1, board, isVisited);
    minV = min(minV, result);
  }
  isVisited[nowY][nowX] = false;
  return minV;
}

int bfs(int nowX, int nowY, int targetX, int targetY, vector<string>& board, bool isVisited[][51]) {
  //x, y, distance
  queue<tuple<int, int, int>> q;
  
  q.push({nowX, nowY, 0});
  int answer = INT32_MAX;
  while(!q.empty()) {
    tuple<int, int, int>& f = q.front();

    int x = get<0>(f);
    int y = get<1>(f);
    int d = get<2>(f);
    q.pop();
    if(x < 0 || y < 0 || y >= board.size() || x >= board[0].length()) continue;
    if(isVisited[y][x]) continue;
    if(board[y][x] == '#') continue;

    if(y == targetY && x == targetX) {
      answer = min(answer, d);
      continue;
    }

    if(d >= answer) continue;

    isVisited[y][x] = true;

    for(int i = 0; i < 4; i++) {
      q.push({x + dx[i], y + dy[i], d + 1});
    }
  }
  return answer;
}

int findTarget(pair<int, int>& from, pair<int, int>& to, vector<string>& board, bool isVisited[][51]) {
  memset(isVisited, false, sizeof(bool) * 51 * 51);
  //vector<vector<bool>> isVisited2(board.size(), vector<bool>(board[0].size(), false));
  return bfs(from.first, from.second, to.first, to.second, board, isVisited);
}

int main() {
  int N, M;
  cin >> M >> N;
  vector<string> board(N);
  vector<pair<int, int>> positions;
  pair<int, int> exit;

  int itemIndex = 1;
  for(int y = 0; y < N; y++) {
    cin >> board[y];
    for(int x = 0; x < M; x++) {
      if(board[y][x] == 'X') {
        board[y][x] = 48 + itemIndex;
        positions.push_back({x, y});
        itemIndex++;
      } else if(board[y][x] == 'S') {
        positions.insert(positions.begin(), {x, y});
      } else if(board[y][x] == 'E') {
        exit = {x, y};
      }
    }
  }

  positions.push_back(exit);

  vector<vector<int>> distance(itemIndex + 1, vector<int>(itemIndex + 1, -1));
  
  // for(int y = 0; y < N; y++) {
  //     cout << board[y] << endl;
  // }

  for(int i = 0; i < positions.size(); i++) {
    for(int k = i; k < positions.size(); k++) {
      if(i == k) continue;
      //cout << "from : " << i << " to : " << k << endl;
      distance[i][k] = findTarget(positions[i], positions[k], board, isVisited);
      distance[k][i] = distance[i][k];
      //cout << "from : " << i << " to : " << k << " => " <<  distance[i][k] << endl;
    }
  }

  vector<int> p;
  for(int i = 0; i < positions.size(); i++) {
    p.push_back(i);
  }
  int minV = INT32_MAX;
  do {
    // for(int i = 0; i < positions.size(); i++) {
    //   cout << p[i] << " ";
    // }
    // cout << endl;
    int sum = 0;
    bool isImpossible = false;
    for(int i = 0; i < positions.size() - 1; i++) {
      if(distance[p[i]][p[i + 1]] == INT32_MAX) {
        // 만약 다음 방향으로 가는 패스가 존재하지 않는다면 
        isImpossible = true;
        break;
      }
      sum += distance[p[i]][p[i + 1]];
      if(sum >= minV) break;
    }
    //cout << "sum : " << sum << endl;
    if(isImpossible) continue;
    
    minV = min(minV, sum);
  } while(next_permutation(p.begin() + 1, p.end() - 1));
  
  cout << minV << endl;
}