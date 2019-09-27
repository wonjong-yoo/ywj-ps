#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  vector<int> s;
  s.reserve(100000);
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    s.push_back(temp);
  }

  sort(s.begin(), s.end());
  int M;
  cin >> M;
  for(int i = 0; i < M; i++) {
    int temp;
    cin >> temp;
    if(std::binary_search(s.begin(), s.end(), temp, [](const auto& a, const auto& b) {
      return a < b;
    })) {
      cout << "1\n";
    } else cout << "0\n";
  }
}