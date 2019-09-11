#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <exception>
#include <vector>
#include <functional>

using namespace std;

int main() {
  int L, C;
  scanf("%d %d", &L, &C);

  set<char> ja;
  set<char> mo;
  vector<char> inputs;
  char enter;
  scanf("%c", &enter);
  for(int i = 0; i < C; i++) {
    char temp;
    scanf("%c", &temp);
    if(temp == 'a' || temp == 'i' || temp == 'o' || temp == 'e' || temp == 'u') mo.insert(temp);
    else ja.insert(temp);

    inputs.push_back(temp);
    scanf("%c", &temp);
  }
  
  vector<int> permutation;
  for(int i = 0; i < L; i++) {
    permutation.push_back(1);
  }

  for(int i = 0; i < C - L; i++) {
    permutation.push_back(0);
  }

  std::sort(permutation.begin(), permutation.end(), std::greater<int>());
  std::sort(inputs.begin(), inputs.end());

  do {
    string now;
    int jaCount = 0;
    int moCount = 0;
    for(int i = 0; i < C; i++) {


      if(permutation[i] == 1) {
        now.push_back(inputs[i]);

        if(ja.find(inputs[i]) != ja.end()) {
          jaCount++;
        } else if(mo.find(inputs[i]) != mo.end()) {
          moCount++;
        } else throw exception();
      }
    }

    if(jaCount >= 2 && moCount >= 1) {
      printf("%s\n", now.c_str());
    }

  } while(prev_permutation(permutation.begin(), permutation.end()));
  
}