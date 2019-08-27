#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(vector<int> &s) {
  cout << "[";
  for_each(s.begin(), s.end(), [](const int& a) {
    cout << a << ", ";
  });
  cout << "]" << endl;
}

int main() {
  int N;
  cin >> N;
  
  vector<int> negativeInputs;
  vector<int> positiveInputs;
  bool isExistZero = false;

  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    if(temp > 0) positiveInputs.push_back(temp);
    else if(temp < 0) negativeInputs.push_back(temp);
    else isExistZero = true;
    
  }
  
  // 양수는 내림차순 정렬
  std::sort(positiveInputs.begin(), positiveInputs.end(), [](const auto& left, const auto& right) {
    if(left > right) return 1;
    else return 0;
  });

  // 음수는 오름차순 정렬
  std::sort(negativeInputs.begin(), negativeInputs.end(), [](const auto& left, const auto& right) {
    if(left > right) return 0;
    else return 1;
  });
  
  //PrintVector(positiveInputs);
  //PrintVector(negativeInputs);
  int answer = 0;

  // 양수 처리
  for(int i = 0; i < positiveInputs.size(); i += 2) {
    if(i + 1 >= positiveInputs.size()) {
      answer += positiveInputs[i];
      break;
    }
    int right = positiveInputs[i];
    int left  = positiveInputs[i + 1];
    
    // cout << right << ", " << left  << endl;
    if(left == 1 || right == 1) answer += right + left;
    else if(left == 0 || right == 0) answer += right + left;
    else answer += right * left;
    

  }
  // cout <<  "answer :  "  <<  answer << endl;

  // 음수처리
  for(int i = 0; i < negativeInputs.size(); i += 2) {
    if(i + 1 >= negativeInputs.size()) {
      // 만약 0이 있다면
      if(isExistZero) break;

      else answer += negativeInputs[i];
      break;
    }

    int left = negativeInputs[i];
    int right = negativeInputs[i + 1];
     //cout << left << ", " << right << endl;
    answer += left  * right;
    //cout <<  "answer :  "  <<  answer << endl;
  }
  cout << answer << endl;

  
}