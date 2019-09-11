#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

void printBoard(vector<vector<int>>& board) {
    for(int i = 0; i < board.size(); i++) {
        for(int k = 0; k < board.size(); k++) {
            cout << board[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

map<int, vector<pair<int, int>>> findBlockPosition(vector<vector<int>>& board) {
    map<int, vector<pair<int, int>>> blockMap;
    
    int N = board.size();
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            if(board[y][x] == 0) continue;
            if(blockMap.count(board[y][x]) == 0) {
                vector<pair<int, int>> newVector;
                newVector.push_back(make_pair(y, x));
                blockMap[board[y][x]] = newVector;
            } else {
                blockMap[board[y][x]].push_back(make_pair(y, x));
            }
        }
    }
    
    return blockMap;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    map<int, vector<pair<int, int>>> blockMap = findBlockPosition(board);
    
    int N = blockMap.size();
    vector<bool> isEliminated(N + 1, false);
    
    bool isFind = true;
    while(isFind) {
        isFind = false;
        for(auto iter = blockMap.begin(); iter != blockMap.end(); ++iter) {
            int blockNumber = iter->first;
            vector<pair<int, int>> blockPositions = iter->second;
            
            if(isEliminated[blockNumber] == true) continue;
            
            // 빈칸의 좌표를 찾는다. 
            int max_y = -1, max_x = -1;
            int min_y = 99999999, min_x = 99999999;
            for(auto& position : blockPositions) {
                int now_y = position.first;
                int now_x = position.second;
                
                max_y = max(max_y, now_y);
                max_x = max(max_x, now_x);
                min_y = min(min_y, now_y);
                min_x = min(min_x, now_x);
            }
            
        
            vector<pair<int, int>> blankPositions;
            for(int y = min_y; y <= max_y; y++) {
                for(int x = min_x; x <= max_x; x++) {
                    if(board[y][x] == 0) {
                        blankPositions.push_back(make_pair(y, x));
                    }
                }
            }
            
            // 빈칸이 두개가 아니라면 
            if(blankPositions.size() != 2) continue;
            
            bool isBlocked = false;
            // 빈칸 2개를 가지고 위에 블럭이 없는지 검사한다.
            for(auto& position : blankPositions) {
                
                int y = position.first;
                int x = position.second;
                
                //cout << "빈칸 y : " << y << ", x : " << x << endl;
                for(int nowY = y - 1; nowY >= 0; nowY--) {
                    if(board[nowY][x] != 0) {
                        isBlocked = true;
                        break;
                    }
                }
                if(isBlocked == true) break;
            }
            
            if(isBlocked == true) continue;

            //위가 막혀있지 않다면 해당 블록을 모두 지운다.
            for(auto& position : blockPositions) {
                int y = position.first;
                int x = position.second;
                
                board[y][x] = 0;
            }
            answer++;
            isFind = true;
            isEliminated[blockNumber] = true;
            //printBoard(board);
        }
    }
    
    
    return answer;
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> board(N, vector<int>(N, 0));
  
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  cout << solution(board);
  
}