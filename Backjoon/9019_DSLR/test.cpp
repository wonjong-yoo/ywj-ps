#include <iostream>
#include <string>
using namespace std;


int RotateLeft(int num) {
  string numToString = to_string(num);
  if(numToString.length() != 4) {
    numToString.push_back('0');
    return stoi(numToString);
  } else {
    char first = numToString[0];
    for(int i = 0; i < 3; i++) {
      numToString[i] = numToString[i + 1];
    }
    numToString[3] = first;

    return stoi(numToString);
  }
}

int RotateRight(int num) {
  string numToString = to_string(num);
  
  char last = numToString[numToString.length() - 1];
  if(numToString.length() == 1 && last == '0') return 0;
  
  numToString.pop_back();
  if(numToString.length() == 0) return (last - 48) * 1000;
  int returnValue = stoi(numToString);
  returnValue += (last - 48) * 1000;
  return returnValue;

}

int main() {
  for(int i = 0; i < 2000; i += 9) {

    cout << "now : " << i << endl;
    cout << "left : " << RotateLeft(i) << endl;
    cout << "right : " << RotateRight(i) << endl; 
    if(1) {

    }
  }
}