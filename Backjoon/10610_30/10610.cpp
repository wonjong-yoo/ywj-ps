#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

int main() {
  string input;
  cin >> input;
  
  vector<int> digits;
  int sum = 0;


  for(int i = 0; i < input.length(); i++) {
    int temp = input[i] - 48;
    sum += temp;

    digits.push_back(temp);
  }

  if(sum % 3 != 0) {
    cout << "-1" << endl;
    return 0;
  }

  std::sort(digits.begin(), digits.end());
  std::reverse(digits.begin(), digits.end());
  
  if(digits[digits.size() - 1] != 0) {
    cout << "-1" << endl;
    return 0;
  }

  for(int i = 0; i < digits.size(); i++) {
    cout << digits[i];
  }

}