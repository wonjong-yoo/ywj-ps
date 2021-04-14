#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>


using namespace std;

void calculateNumOfCasesByN(vector<type>& types, unordered_map<string, unordered_set<string>>& namesByType, int n) {
  vector<int> forPermutation;
  for(int i = 0; i < n; i++) {
    forPermutation.push_back(1);
  }

  for(int i = n; i < types.size(); i++) {
    forPermutation.push_back(0);
  }

  assert(forPermutation.size() == types.size());

  do {
    vector<int> selectedIndexes;
    for(int i = 0; i < forPermutation.size(); i++) {
      if (forPermutation[i] == 1) {
        selectedIndexes.push_back(i);
      }
    }

    
  } while(next_permutation(forPermutation.begin(), forPermutation.end()));

}

int calculateNumOfCases(unordered_map<string, unordered_set<string>>& namesByType) {
  int numOfClasses = namesByType.size();
  vector<string> types;

  for(auto& iter = namesByType.begin(); iter != namesByType.end(); iter++) {
    int type = iter->first;
    types.push_back(type);
  }

  for(int i = 1; i <= numOfClasses; i++) {
    
  }
}

int main() {
  int N;
  cin >> N;


  for(int i = 0; i < N; i++) {
    int M;
    cin >> M;
    for(int k = 0; k < M; k++) {
      unordered_map<string, unordered_set<string>> NamesByType;

      string type, name;
      cin >> type, name;

      if(NamesByType.find(type) != NamesByType.end()) {
        auto& names = NamesByType[type];
        names.insert(name);
      } else {
        unordered_set<string> names;
        names.insert(name);
        input.insert(make_pair(type, names)))
      }
    }
  }
}