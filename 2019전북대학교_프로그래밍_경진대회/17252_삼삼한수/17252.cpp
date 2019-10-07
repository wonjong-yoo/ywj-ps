#include <vector>
#include <iostream>

#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  unsigned long long target;
  cin >> target;
  if(target == 0) {
    cout << "NO\n";
    return 0;
  }
  vector<unsigned long long> v;
  for(int i = 0; i < 20; i++) {
    v.push_back(pow(3, i));
  }

  for(int i = 1; i <= 20; i++) {
    vector<int> p;
    for(int k = 0; k < i; k++) {
      p.push_back(1);
    }

    for(int k = 0; k < 20 - i; k++) {
      p.push_back(0);
    }
    sort(p.begin(), p.end());
    
    do {
      unsigned long long sum = 0;
      for(int k = 0; k < 20; k++) {
        if(p[k] == 1) {
          sum += v[k];
        }
        if(sum == target) {
          cout << "YES\n";
          return 0;
        } else if(sum > target) {
          break;
        }
      }


    } while(next_permutation(p.begin(), p.end()));

  }
  cout << "NO\n";
}