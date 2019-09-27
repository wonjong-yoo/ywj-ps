#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < M; x++) {
      int R, G, B;
      cin >> R >> G >> B;
      int intensity = 2126 * R + 7152 * G + 722 * B;
      if(intensity >= 0 && intensity < 510000) cout << "#";
      else if(intensity < 1020000) cout << "o";
      else if(intensity < 1530000) cout << "+";
      else if(intensity < 2040000) cout << "-";
      else cout << ".";
    }
    cout << "\n";
  }
  
}