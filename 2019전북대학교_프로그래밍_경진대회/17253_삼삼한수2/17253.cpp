#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
int main() {
  vector<ull> v;
  ull di = 1;
  for(int i = 0; i < 40; i++) {
    v.push_back(di);
    di *= 3;
  }

  ull target;
  cin >> target;
  if(target == 0) {
    cout << "NO\n";
    return 0;
  }
  for(int i = v.size() - 1; i >= 0; i--) {
    if(v[i] <= target) target -= v[i];
    //cout << target << endl;
    if(target == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}

