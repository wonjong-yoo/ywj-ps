#include <string>
#include <vector>
#include <iostream>
using namespace std;

int split(string& p, int start, int end) {
    int left  = 0;
    int right = 0;
    
    for(int i = start; i <= end; i++) {
        if(p[i] == '(') ++left;
        else if(p[i] == ')') ++right;
        if(left != 0 && right != 0 && left == right) return i;
    }
    
}

bool isRightString(string& p, int start, int end) {
  p.
    vector<char> v;
    for(int i = start; i <= end; i++) {
        if(p[i] == '(') {
            v.push_back('(');
        } else if(p[i] == ')') {
          if(v.size() == 0) return false;
            if(v.back() == '(') {
                v.pop_back();
            } else {
                return false;
            }
        }
    }
    return true;
}

void reverse(string& p) {
    for(int i = 0; i < p.length(); i++) {
        if(p[i] == ')') p[i] = '(';
        else if(p[i] == '(') p[i] = ')';
    }
}

string recursion(string& p, int start, int end) {
    cout << p.substr(start, end-start) << endl;
    if(start > end) return "";
    if(p.length() == 0) return "";
    int mid;
    mid = split(p, start, end);
    cout << "mid : " << mid << endl;
    // u 
    // u가 올바른 문자열이 아닐경우
    if(!isRightString(p, start, mid)) {
        string temp = "(";
        // v
        temp += recursion(p, mid + 1, end);
        temp += ")";
        string nextU = p.substr(start + 1, mid - start - 1);
        reverse(nextU);
        temp += nextU;
        return temp;
    } else { // u가 올바른 문자열읽 ㅕㅇ우
        string rv = recursion(p, mid + 1, end);
        return p.substr(start, (mid - start)) + rv;
    }
        
}

string solution(string p) {
    string answer = recursion(p, 0, p.length() - 1);
    
    return answer;
}

int main() {
  string a;
  cin >> a;
  cout << solution(a);
}