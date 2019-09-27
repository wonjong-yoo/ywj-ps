#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <algorithm>
#include <exception>
#include <vector>

using namespace std;

int recursion(string input) {
  int inputLength = input.length();
  if(inputLength == 1) {
    return input[0] - 48;
  }

  if(inputLength == 3) {
    char operand = input[1];
    if(operand == '+') {
      return input[0] - 48 + input[2] - 48;
    } else if(operand == '-') {
      return input[0] - 48 - input[2] - 48;
    } else if(operand == '*') {
      return (input[0] - 48) * (input[2] - 48);
    } else throw exception();
  }
  int maxValue = 0;
  for(int i = 1; i < input.length() - 1; i+= 2) {
    char operand = input[i];
    string left = input.substr(0, i);
    string right = input.substr(i + 1, input.length() - i - 1);
    cout << "left : " << left << ", right : " << right << endl;
    int evaluatedLeft = recursion(left);
    int evaluatedRight = recursion(right);
    int result;
    if(operand == '+') {
      result =  evaluatedLeft + evaluatedRight;
    } else if(operand == '-') {
      result =  evaluatedLeft - evaluatedRight;
    } else if(operand == '*') {
      result = evaluatedLeft * evaluatedRight;
    } else throw exception();
    cout << "result : " << result << endl;
    maxValue = max(result, maxValue);
  }
  cout << "max : " << maxValue << endl;
  return maxValue;
}

int op(char operand, int a, int b) {
    if(operand == '+') {
      return a + b;
    } else if(operand == '-') {
      return a - b;
    } else if(operand == '*') {
      return a * b;
    } else throw exception();
}

// 괄호 안치고 치고 안치고...
// flag는 마지막 괄호인지 체크
int calc(string input, bool flag) {
  int inputLength = input.length();
  if(inputLength == 1) {
    return input[0] - 48;
  }

  if(inputLength == 3) {
    char operand = input[1];
    if(operand == '+') {
      return input[0] - 48 + input[2] - 48;
    } else if(operand == '-') {
      return input[0] - 48 - input[2] - 48;
    } else if(operand == '*') {
      return (input[0] - 48) * (input[2] - 48);
    } else throw exception();
  }

  

}

int main() {
  int n;
  string input;
  cin >> n;
  cin >> input;
  
  if(n == 1) {
    cout << input[0] << endl;
    return 0;
  } else if(n == 3) {
    if(input[1] == '-') {
      cout << (input[0] - 48 - input[2] - 48);
    } else if(input[1] == '+') {
      cout << (input[0] - 48 + input[2] - 48);
    } else if(input[1] == '*') {
      cout << ((input[0] - 48) * (input[2] - 48));
    }
    return 0;
  }

  for(int i = 0; i < (input.size() - 2) / 2; i++) {
    //i는 1의 개수
    vector<int> p;
    for(int k = 0; k < (input.size() / 2) + 1 - i * 2; k++) {
      p.push_back(0);
    }
    for(int k = 0; k < i; k++) {
      p.push_back(1);
    }
    sort(p.begin(), p.end());

    do {
      vector<int> s;
      int nowIndex = 0;
      for(int k = 0; k < p.size(); k++) {
        if(nowIndex >= input.size()) break;
        if(p[k] == 0) {
          s.push_back(input[nowIndex++] - 48);
        } else {
          int left = input[nowIndex++];
          char operator2 = input[nowIndex++];
          int right = input[nowIndex++];
          s.push_back(op(operator2, left - 48, right - 48));
        }
        //operator 삽입
        if(nowIndex >= input.size()) break;
        if(nowIndex != input.size() - 1) {
          s.push_back(input[nowIndex++]);
        }
      }
      cout << string(s.begin(), s.end()) << endl;
      vector<int> afterMulti;
      for(int j = 0; j < s.size(); j++) {
        int now = s[j];
        if(now == '*') {
          int previous = afterMulti.back();
          int next = s[++j];
          
          afterMulti.pop_back();
          
          afterMulti.push_back((previous) * (next));
        } else if(now == '-' || now == '+') afterMulti.push_back(now);  
        else afterMulti.push_back(now);       
      }
      cout << " now : ";
      for(int j = 0; j < afterMulti.size(); j++) {
        if(afterMulti[j] == '-' || afterMulti[j] == '+' || afterMulti[j] == '*') cout << "\"" << char(afterMulti[j]) <<"\"";
        else cout << afterMulti[j];
      }
      cout << endl;
      
      while(afterMulti.size() != 1) {
        int operand1 = afterMulti.back();
        afterMulti.pop_back();
        int operator2 = afterMulti.back();
        afterMulti.pop_back();
        int operand2 = afterMulti.back();
        afterMulti.pop_back();

        if(operator2 == '-') {
          afterMulti.push_back(operand2 - operand1);
        } else if(operator2 == '+') {
          afterMulti.push_back(operand2 + operand1);
        } else throw exception();
      }

      cout << afterMulti[0] << endl;

    } while(next_permutation(p.begin(), p.end()));
  }
  
}