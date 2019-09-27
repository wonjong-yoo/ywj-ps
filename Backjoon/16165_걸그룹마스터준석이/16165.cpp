#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {

  map<string, set<string>> girlGroupNameMap;
  map<string, string> girlGroupMemberMap;

  int N, M;
  cin >> N >> M;
  for(int n = 0; n < N; n++) {
    string girlGroupName;
    cin >> girlGroupName;
    
    int girlGroupNum;
    cin >> girlGroupNum;
    set<string> girlGroupMembers;
    for(int i = 0; i < girlGroupNum; i++) {
      string name;
      cin >> name;
      girlGroupMembers.insert(name);
      girlGroupMemberMap[name] = girlGroupName;
    }
    girlGroupNameMap[girlGroupName] = girlGroupMembers;
  }  

  for(int i = 0; i < M; i++) {
    string name;
    int mode;
    cin >> name  >> mode;
    if(mode == 0) {
      set<string>& girlGroupMembers = girlGroupNameMap[name];
      for(auto iter = girlGroupMembers.begin(); iter != girlGroupMembers.end(); iter++) {
        cout << *iter << "\n";
      }
    } else if(mode == 1) {
      cout << girlGroupMemberMap[name] << "\n";
    }
  }
}