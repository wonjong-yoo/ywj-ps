#include <iostream>
#include <string>

using namespace std;

string solution(string m, string k) {
  string answer;
  answer.reserve(m.size());
  
  int keyIndex = 0;
  for (int i = 0; i < m.size(); i++) {
    if (keyIndex >= k.size()) {
      answer.push_back(m[i]);
      continue;
    }

    if (m[i] == k[keyIndex]) {
      keyIndex++;
      continue;
    }
    
    answer.push_back(m[i]);
  }

  return answer;
}

void test1() {
  string m = "kkaxbycyz";
  string k = "abc";

  string answer = solution(m, k);
  cout << answer << endl;
}

void test2() {
  string m = "acbbcdc";
  string k = "abc";

  string answer = solution(m, k);
  cout << answer << endl;
}

// 97 ~ 122
// void test3() {
//   std::srand(5323); // 시드값을 5323으로 설정한다.

//   string m = "abceerqqwrqd";
//   for (int i = 0; i < 10000000; i++) {
//     m += (std::rand() % 25 + 97);
//   }
//   string k = "casfasefaesfesfsefd";

//   string answer = solution(m, k);
//   // cout << answer << endl;
// }


int main() {
  test1();
  test2();
  // test3();
}