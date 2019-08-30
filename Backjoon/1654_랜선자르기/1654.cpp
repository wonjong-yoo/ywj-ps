#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int K, N;
  cin >> K >> N;

  vector<int> existLine;
  for(int i = 0; i < K; i++) {
    int temp;
    cin >> temp;
    existLine.push_back(temp);
  }
  // 내림차순 정렬
  std::sort(existLine.begin(), existLine.end(), [](const auto& left, const auto& right) {
    return left > right;
  });
  int sumOfSplitedLineNum = existLine.size();
  int firstSplitLine = 2;
  int splitLineLength = 0;

  while(sumOfSplitedLineNum < N) {
    // 초기화
    splitLineLength = 0;
    sumOfSplitedLineNum = existLine.size();
    splitLineLength = existLine[0] / firstSplitLine;
    sumOfSplitedLineNum += firstSplitLine - 1;  

    //cout << "First : " << splitLineLength << endl;

    for(int i = 1; i < existLine.size() && sumOfSplitedLineNum < N; i++) {
      int splitedLineNum = existLine[i] / splitLineLength;
      sumOfSplitedLineNum += splitedLineNum - 1;
    }
    //cout << "sum : " << sumOfSplitedLineNum << endl;
    firstSplitLine++;
    //getchar();
  }

  cout << splitLineLength << endl;


}