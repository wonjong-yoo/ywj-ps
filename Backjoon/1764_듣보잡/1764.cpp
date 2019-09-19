#include <set>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  set<string> noHearPersons;
  for(int i = 0; i < N; i++) {
    string temp;
    cin >> temp;
    noHearPersons.insert(temp);
  }

  set<string> noHearAndSeePersons;
  for(int i = 0; i < M; i++) {
    string temp;
    cin >> temp;
    if(noHearPersons.find(temp) != noHearPersons.end()) noHearAndSeePersons.insert(temp);
  }

  cout << noHearAndSeePersons.size() << "\n";
  for(auto iter = noHearAndSeePersons.begin(); iter != noHearAndSeePersons.end(); iter++) {
    cout << *iter << "\n";
  }
}