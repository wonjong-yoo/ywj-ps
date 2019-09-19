#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
const int COMPUTED_NOTHING = 0;
const int COMPUTED_LEFT = 1;
const int COMPUTED_RIGHT = 2;

int calc(string& text, string& find) {
  int code = COMPUTED_NOTHING;
  string left, right;
  left.reserve(text.length());
  right.reserve(text.length());
  int leftIndex = 0;
  int rightIndex = text.length() -1;
  while(leftIndex <= rightIndex) {
    // 왼쪽부터 검색
    for(int i = leftIndex; i <= rightIndex; i++, leftIndex++) {
      //cout << "1left : " << left << " right : " << right << endl;
      
      int flag = false;
      int count = 0;
      for(int k = 0; i <= rightIndex && k < find.length(); i++, k++, leftIndex++) {
        left.push_back(text[i]);
        count++;
        if(find[k] != text[i]) {
          leftIndex -= count - 1;
          i -= count -1;
          for(int j = 0; j < count - 1; j++) {
            left.pop_back();
          }
          flag = true;
          break;
        } else {
          
        }
      }
      
      if(flag == false && count == find.length()) {
        //cout << "LEFT POP" << endl;
        code += COMPUTED_LEFT;
        for(int k = 0; k < find.length(); k++) {
          left.pop_back();
        }
        break;
      }
      //cout << "2left : " << left << " right : " << right << endl;
    }

    //오른쪽 검색
    for(int i = rightIndex; i >= leftIndex; i--, rightIndex--) {
      //cout << "3left : " << left << " right : " << right << endl;
      
      int flag = false;
      int count = 0;
      for(int k = find.length() - 1; i >= leftIndex && k >= 0; i--, k--, rightIndex--) {
        right.push_back(text[i]);
        count++;
        if(find[k] != text[i]) {
          rightIndex += count - 1;
          i += count - 1;
          for(int j = 0; j < count - 1; j++) {
            right.pop_back();
          }
          flag = true;
          break;
        }
      }

      if(flag == false && count == find.length()) {
        code += COMPUTED_RIGHT;
        //cout << "RIGHT POP" << endl;
        for(int k = 0; k < find.length(); k++) {
          right.pop_back();
        }
        break;
      }
      //cout << "4left : " << left << " right : " << right << endl;
    }
    
  }

  reverse(right.begin(), right.end());
  text = left + right;
  return code;
}

int main() {
  string find, text;
  cin >> find;
  cin >> text;
  
  int code = calc(text, find);
  //cout << "text : " << text << endl;
  while(code) {
    code = calc(text, find);
    //cout << "text : " << text << endl;
  }
  cout << text << endl;
}