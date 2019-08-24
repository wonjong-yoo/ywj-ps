#include <iostream>
#include <vector>

using namespace std;

vector<int> coinValues;

int main() {
  int numOfCoin, sumOfMoney;

  cin >> numOfCoin >> sumOfMoney;
  for(int i = 0; i < numOfCoin; i++) {
    int temp;
    cin >> temp;
    coinValues.push_back(temp);
  }

  int nowMoney = sumOfMoney;
  int needCoin = 0;
  for(int i = numOfCoin - 1; i >= 0; i--) {
    needCoin += (nowMoney / coinValues[i]);
    nowMoney %= coinValues[i];
  }

  cout << needCoin << endl;

}