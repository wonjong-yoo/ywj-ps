#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <cstdio>
using namespace std;


void deleteString(string& text, int length) {
  for(int i = 0; i < length; i++) {
    text.pop_back();
  }
}

string calc(string& text, string& find) {
  string buffer;
  buffer.reserve(text.length());
  int leftIndex = 0;
  int textLength = text.length();
  while(leftIndex < textLength) {
   
    // 먼저 buffer를 먼저 탐색한다.
    int findIndex = 0;
    int foundCount = 0;
    bool isFound = true;
    for(int i = 0; i < buffer.length(); i++) {
      isFound = true;
      for(int bufferIndex = i, findIndex = 0; bufferIndex < buffer.length() && findIndex < find.length(); bufferIndex++, findIndex++) {
        if(find[findIndex] != buffer[bufferIndex]) {
          isFound = false;
          foundCount = 0;
          break;
        } else {
          foundCount++;
        }
      }
      if(isFound == true) {
        findIndex++;
        break;
      }
    } 

    if(isFound && foundCount == find.length()) {
      deleteString(buffer, foundCount);
      continue;
    }

   // 다음 문자열을 탐색한다.
    int previousFindIndex = findIndex;
    int previousFoundCount = foundCount;
    //int previousLeftIndex = leftIndex;
    for(; leftIndex < textLength; leftIndex++) {
        isFound = true;
        for(int i = leftIndex; i < textLength && findIndex < find.length(); i++, findIndex++) {
          if(find[findIndex] != text[i]) {

            // 만약 foundCount가 0이라면 buffer에 하나 넣는다.
            if(foundCount == 0) buffer.push_back(text[i]);
            else {
              buffer.insert(buffer.length(), text.substr(i - foundCount + previousFoundCount, max(1, foundCount - previousFoundCount)));
              leftIndex += foundCount - previousFoundCount;
            }

            isFound = false;
            findIndex = previousFindIndex;
            foundCount = previousFoundCount;
            break;
          } else foundCount++;
        }
        
        if(isFound && foundCount == find.length()) {
          break;
        }
    }
    //cout << "leftIndex " << leftIndex << ", " << "foundCount : " << foundCount << endl;
    if(isFound && foundCount == find.length()) {
      deleteString(buffer, previousFoundCount);
      leftIndex += foundCount - previousFoundCount;
    } else if(isFound && leftIndex + foundCount - 1 == textLength) {
      //cout << "TEST" << endl;
      buffer += text.substr(leftIndex - 1, foundCount);
    }
    // } else {
    //   // 못찼았다면 leftIndex만큼 버퍼에 넣는다.
    //   leftIndex = min(textLength - 1, leftIndex + foundCount);
    //   buffer.insert(buffer.length() - 1, text.substr(previousLeftIndex, leftIndex));
    // }
  }
  return buffer;
}

bool isErased[1000001];

void explosion(string& text, string& find) {
  stack<pair<int, int>> s;
  int textLength = text.length();
  int findLength = find.length();
  for(int i = 0; i < textLength; i++) {
    if(s.empty()) {
      if(text[i] == find[0]) s.push(make_pair(i, 0));
      else isErased[i] = false;
      continue;
    }
    
    pair<int, int> top = s.top();
    int nextFindIndex = top.second + 1;
    int nowTextIndex = top.first;


    if(text[i] == find[nextFindIndex]) {
      s.push(make_pair(i, nextFindIndex));
    } else if(text[i] == find[0]) {
      s.push(make_pair(i, 0));
      continue;
    } else {
      while(!s.empty()) {
        s.pop();
      }
      continue;
    }
    

    if(nextFindIndex + 1 == findLength) {
      for(int k = 0; k < findLength; k++) {
        int index = s.top().first;
        isErased[index] = true;
        s.pop();
      }
      continue;
    }
  }
}

int main() {
  char textChar[1000001];
  char findChar[101];
  scanf("%s", textChar);
  scanf("%s", findChar);

  string find(findChar);
  string text(textChar);
  
  if (find.length() == 1) {
      for (int i=0; i<text.length(); i++) {
          if (text[i] == find[0]) {
              isErased[i] = true;
          }
      }
  } else {
    explosion(text, find);
  }
  


  bool isFound = false;
  for(int i = 0; i < text.length(); i++) {
    if(isErased[i] == false) {
      isFound = true;
      printf("%c", text[i]);
    }
  }
  if(isFound == false) printf("FRULA");

  printf("\n");
  
}