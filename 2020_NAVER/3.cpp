#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, vector<vector<int>> egdes) {
  vector<int> numOfChildNode(n);
  unordered_map<int, vector<int>> childNodeByNodeNum;
  for (int i = 0; i < n; i++) {
    childNodeByNodeNum.insert(make_pair(i, vector<int>()));
  }

  


}

int main() {

}