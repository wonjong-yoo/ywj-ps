#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  auto comparator = [](const string& left, const string& right) {
    // int minLength = min(left.length(), right.length());
    // for(int i = 0; i < minLength; i++) {
    //   if(left[i] == right[i]) continue;
    //   else return left[i] > right[i]; 
    // }
    return left.compare(right) > 0;
    
  };

  auto now = set<string, decltype(comparator)>(comparator);

  //now.reserve(1000000);
  for(int i = 0; i < N; i++) {
    string person;
    string mode;
    cin >> person >> mode;
    if(mode == "enter") {
      now.insert(person);
    } else if(mode == "leave") {
      now.erase(person);
    }
  }

  for(auto iter = now.begin(); iter != now.end(); iter++) {
    cout << *iter << "\n";
  }
}