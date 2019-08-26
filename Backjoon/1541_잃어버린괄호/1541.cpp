#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <exception>

using namespace std;

const int PLUS = -1;
const int MINUS = -2;


bool isNumber(char target) {
  if(target >= '0' && target <= '9')
    return true;
  else return false;
}

void printStack(vector<int> &s) {
  cout << "[";
  for_each(s.begin(), s.end(), [](const int& a) {
    cout << a << ", ";
  });
  cout << "]" << endl;
}

int main() {
  string input;
  cin >> input;
  

  vector<int> opStack;
  for(int i = 0; i < input.length(); i++) {
    if(isNumber(input[i])) {
      int k = i;
      for(; isNumber(input[k]) && k < input.length(); k++) {}
      int number = std::stoi(input.substr(i, k - i));
      i = k - 1;
      // cout << number << endl;
      opStack.push_back(number);
    }
    else if(input[i] == '+') {
      // cout << "+" << endl;
      opStack.push_back(PLUS);
    }
    else if(input[i] == '-') {
      // cout << "-" << endl;
      opStack.push_back(MINUS);
    }
    else throw new exception();
  }

  int answer = 0;
  while(!opStack.empty()) {
    // 피연산자를 얻는다.
    int operand = opStack.back();
    opStack.pop_back();
    if(opStack.empty()) {
      answer += operand;
      break;
    }
    // 연산자를 얻는다.
    int Operator = opStack.back();
    opStack.pop_back();
    
    if(Operator == PLUS) {
      int secondOperand = opStack.back();
      opStack.pop_back();
      // answer = operand + secondOperand;
      opStack.push_back(operand + secondOperand);
    } else if(Operator == MINUS) {
      answer += -operand;
      // opStack.push_back(PLUS);
      // opStack.push_back(answer);
    } else throw new exception();

    // printStack(opStack);

    // cout << answer << endl;
  }

  cout << answer << endl;
}

// 20-20-20+40+40+40+40-20+40