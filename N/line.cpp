#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class MyTree {
  public:
    string directory;
    vector<MyTree*> child;

    MyTree(string& d) {
      this->directory = d;
    }

    void insert(vector<string>& directories, int now) {
      if (directories.size() == now) {
        
      }

      if (directory == directories[now]) {
        for (int i = 0; i < child.size(); i++) {
          child[i]->insert(directories, now + 1);
        }
      }
    }
};

vector<string> tokenizing(string& input) {
  vector<string> tokens;
  // 맨 첫 글자가 구분자인 경우 무시
  string::size_type lastPos = input.find_first_not_of("/", 0);
  // 구분자가 아닌 첫 글자를 찾는다
  string::size_type pos     = input.find_first_of("/", lastPos);

  while (string::npos != pos || string::npos != lastPos)
  {
      // token을 찾았으니 vector에 추가한다
      tokens.push_back(input.substr(lastPos, pos - lastPos));
      // 구분자를 뛰어넘는다.  "not_of"에 주의하라
      lastPos = input.find_first_not_of("/", pos);
      // 다음 구분자가 아닌 글자를 찾는다
      pos = input.find_first_of("/", lastPos);
  }
  for(int k = 0; k < tokens.size(); k++) {
    cout << tokens[k] << "/n";
  }
  return tokens;
}

vector<string> solution(vector<string> directory, vector<string> command) {
  MyTree root(directory[0]);
  //루트는 /라고 가정한다.
  for(int i = 1; i < directory.size(); i++) {
    vector<string> tokens = tokenizing(directory[i]);
    
  }
}

int main() {
  vector<string> directory;
  directory.push_back("/");
  directory.push_back("/hello");
  directory.push_back("/hello/tmp");
  directory.push_back("/root");
  directory.push_back("/root/abcd");
  directory.push_back("/root/abcd/etc");
  directory.push_back("/root/abcd/hello");

  vector<string> command;
  command.push_back("mkdir /root/tmp");
  command.push_back("cp /hello /root/tmp");
  command.push_back("rm /hello");

  solution(directory, command);
}





