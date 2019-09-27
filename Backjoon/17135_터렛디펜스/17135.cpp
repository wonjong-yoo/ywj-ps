#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

auto ahash = [](const pair<int, int>& now) {
  return (size_t)(now.first * 10000 + now.second);
};

auto aequal = [](const pair<int, int>& left, const pair<int, int>& right) {
  return (left.first == right.first && left.second == right.second);
};

bool isVisited[26][26];

pair<int, int> BFS(int archorX, int archorY, int enemyMove, int D, vector<vector<int>>& board, unordered_set<pair<int, int>, decltype(ahash), decltype(aequal)>& dead) {
  int N = board.size() - 1;
  int M = board[0].size() - 1;
  
  queue<tuple<int, int, int>> q;
  memset(isVisited, false, sizeof(bool) * 26 * 26);
  q.push({archorX, archorY - 1 - enemyMove, 1});
  while(!q.empty()) {
    
    int x = get<0>(q.front());
    int y = get<1>(q.front());
    int d = get<2>(q.front());
    q.pop();
    if(d > D) return pair<int, int>({-1, -1});
    if(!(x >= 1 && x <= M && y >= 1 && y <= N)) continue;
    if(isVisited[y][x]) continue;
    isVisited[y][x] = true;

    if(board[y][x] == 1 && dead.find({x, y}) == dead.end()) return pair<int, int>({x, y});
    q.push({x - 1, y, d + 1});
    q.push({x, y - 1, d + 1});
    q.push({x + 1, y, d + 1});
  
  }
  
  return pair<int, int>({-1, -1});

}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M, D;
  cin >> N >> M >> D;

  vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));

  for(int y = 1; y <= N; y++) {
    for(int x = 1; x <= M; x++) {
      cin >> board[y][x];
    }
  }

  // 순열을 만든다.
  vector<int> p;
  for(int i = 1; i <= 3; i++) {
    p.push_back(1);
  }
  for(int i = 1; i <= M - 3; i++) {
    p.push_back(0);
  }

  sort(p.begin(), p.end());


  int answer = 0;
  do {
    // 죽은 적의 좌표
    auto dead = unordered_set<pair<int, int>, decltype(ahash), decltype(aequal)>(1000, ahash, aequal);

    int natureDead = 0;
    // 현재 궁수의 x 좌표
    vector<int> archors;
    for(int i = 0; i < p.size(); i++) {
      if(p[i] == 1) {
        archors.push_back(i + 1);
      }
    }

    // 적이 이동한 거리
    for(int enemyMove = 0; enemyMove <= N; enemyMove++) {
      vector<pair<int, int>> temp;
      for(int i = 0; i < archors.size(); i++) {
        // 거리 안에 있는지?
        int archorY = N + 1;
        int archorX = archors[i];
        
        pair<int, int> result = BFS(archorX, archorY, enemyMove, D, board, dead);
        // 범위내에 없을 경우
        if(result.first == -1) {
          
        } else { // 범위내에 있을 경우
          temp.push_back({result.first, result.second});
          
          //cout << "DEAD : " << result.first << ", " << result.second << endl;
          continue;
        }
      }
      for(int i = 0; i < temp.size(); i++) {
        dead.insert({temp[i].first, temp[i].second});
      }

      // 마지막 줄에서 안죽고 살아남은 적을 제거
      for(int x = 1; x <= M; x++) {
        int y = N - enemyMove;
        
        // 만약 해당 적이 안죽었다면
        if(board[y][x] == 1 && dead.find({x, y}) == dead.end()) {
          dead.insert({x, y});
          //cout << "NATURE : " << x << ", " << y << endl;
          natureDead++;
        }
      }
      //cout << enemyMove << " : " << dead.size() << ", " << natureDead << endl;
    }
    answer = max(answer, (int)dead.size() - natureDead);

  } while(next_permutation(p.begin(), p.end()));

  cout << answer << "\n";
}

// if(abs(archorY - y - enemyMove) + abs(archorX - x) <= D && dead.find({x, y}) == dead.end()) {
//     cout << "DEAD : " << x << ", " << y << endl;
//     dead.insert({x, y});
//     break;
//   }