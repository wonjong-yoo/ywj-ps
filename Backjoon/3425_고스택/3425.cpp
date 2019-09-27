#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

void cal(vector<pair<string, int>>& commands, int input) {
  vector<int> s;
  s.push_back(input);
  for(int i = 0; i < commands.size(); i++) {
    string nowCommand = commands[i].first;
    int nowNum = commands[i].second;

    if(nowCommand == "NUM") {
      s.push_back(nowNum);
    } else if(nowCommand == "POP") {
      if(s.size() == 0) {
        cout << "ERROR\n";
        return;
      }
      s.pop_back();
    } else if(nowCommand == "INV") {
      if(s.size() == 0) {
        cout << "ERROR\n";
        return;        
      }
      s[s.size() - 1] = -s.back();
    } else if(nowCommand == "DUP") {
      if(s.size() == 0) {
        cout << "ERROR\n";
        return;        
      }
      s.push_back(s.back());
    } else if(nowCommand == "SWP") {
      if(s.size() < 2) {
        cout << "ERROR\n";
        return; 
      }
      int left = s.back();
      int right = s[s.size() - 2];

      s[s.size() - 1] = right;
      s[s.size() - 2] = left;
      
    } else if(nowCommand == "ADD") {
      if(s.size() < 2) {
        cout << "ERROR\n";
        return; 
      }
      int left = s.back();
      int right = s[s.size() - 2];
      s.pop_back(); s.pop_back();
      if(abs(left + right) > 1000000000) {
        cout << "ERROR\n";
        return; 
      }
      s.push_back(left + right);
    } else if(nowCommand == "SUB") {
      if(s.size() < 2) {
        cout << "ERROR\n";
        return; 
      }
      int left = s.back();
      int right = s[s.size() - 2];
      s.pop_back(); s.pop_back();
      if(abs(right - left) > 1000000000) {
        cout << "ERROR\n";
        return; 
      }
      s.push_back(right - left);

    } else if(nowCommand == "MUL") {
      if(s.size() < 2) {
        cout << "ERROR\n";
        return; 
      }
      int left = s.back();
      int right = s[s.size() - 2];
      s.pop_back(); s.pop_back();
      if(abs((long long)left * (long long)right) > (long long)1000000000) {
        cout << "ERROR\n";
        return; 
      }
      s.push_back(right * left);
    } else if(nowCommand == "DIV") {
      if(s.size() < 2) {
        cout << "ERROR\n";
        return; 
      }
      int left = s.back();
      int right = s[s.size() - 2];
      s.pop_back(); s.pop_back();
      if(left == 0) {
        cout << "ERROR\n";
        return; 
      }
      if(abs(right / left) >= 1000000000) {
        cout << "ERROR\n";
        return; 
      }
      s.push_back(right / left);
    } else if(nowCommand == "MOD") {
      if(s.size() < 2) {
        cout << "ERROR\n";
        return; 
      }
      int left = s.back();
      int right = s[s.size() - 2];
      if(left == 0) {
        cout << "ERROR\n";
        return; 
      }
      s.pop_back(); s.pop_back();
      s.push_back(right % left);
    }

    // cout << "now stack : ";
    // for(int i = 0; i < s.size(); i++) {
    //   cout << s[i] << " ";
    // }
    // cout << endl;
  }
  if(s.size() == 1) {
    cout << s[0] << "\n";
  } else {
    cout << "ERROR\n";
  }
}

int main() {
  while(true) {
    vector<pair<string, int>> s;
    for(;;) {
      string command;
      cin >> command;
      if(command == "QUIT") {
        return 0;
      }

      if(command == "END") {
        //s.push_back({command, 0});
        break;
      }

      if(command == "NUM") {
        int temp;
        cin >> temp;
        s.push_back({command, temp});
        continue;
      } 

      s.push_back({command, 0});
    }

    int N;
    cin >> N;
    vector<int> inputs(N, 0);
    for(int i = 0; i < N; i++) {
      cin >> inputs[i];
      cal(s, inputs[i]);
    }
    cout << "\n";

  
  }

  
}
