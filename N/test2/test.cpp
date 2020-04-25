#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_set>

typedef long long LL;

using namespace std;

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
  map<string, LL> accounts;
  for(int i = 0; i < snapshots.size();  i++) {
    string& accountName = snapshots[i][0];
    LL money = stoll(snapshots[i][1]);
    accounts.insert(make_pair(accountName, money));
  }

  // 트랜잭션 처리한 ID들
  unordered_set<int> processedTransactions;

  for(int i = 0; i < transactions.size(); i++) {
    cout << transactions[i][3] << endl;
    int transactionId = stoi(transactions[i][0]);
    string& action = transactions[i][1];
    string& accountName = transactions[i][2];
    LL money = stoll(transactions[i][3]);
    
    if (processedTransactions.find(transactionId) != processedTransactions.end()) {
      continue;
    }
    
    processedTransactions.insert(transactionId);

    map<string, LL>::iterator now = accounts.find(accountName);
    // 계좌정보가 없다면 계좌 추가
    if (now == accounts.end()) {
      accounts.insert(make_pair(accountName, money));
      continue;
    } 
    
    if (action == "SAVE") {
      now->second = now->second + money;
    } else if (action == "WITHDRAW") {
      now->second = now->second - money;
    }

  }

  // for(map<string, LL>::iterator it = accounts.begin(); it != accounts.end(); it++) {
  //   cout << "[" << it->first << "] : " << it->second << endl;
  // }

  vector<vector<string>> answer;
  for(map<string, LL>::iterator it = accounts.begin(); it != accounts.end(); it++) {
    vector<string> a; 
    
  }
}

int main() {
  vector<vector<string>> snapshots;
  snapshots.push_back(vector<string>());
  snapshots[0].push_back("ACCOUNT1");
  snapshots[0].push_back("100");

  snapshots.push_back(vector<string>());
  snapshots[1].push_back("ACCOUNT2");
  snapshots[1].push_back("150");

  vector<vector<string>> transactions;
  transactions.push_back(vector<string>());
  transactions[0].push_back("1");
  transactions[0].push_back("SAVE");
  transactions[0].push_back("ACCOUNT2");
  transactions[0].push_back("100");

  transactions.push_back(vector<string>());
  transactions[1].push_back("2");
  transactions[1].push_back("WITHDRAW");
  transactions[1].push_back("ACCOUNT1");
  transactions[1].push_back("50");

  transactions.push_back(vector<string>());
  transactions[2].push_back("1");
  transactions[2].push_back("SAVE");
  transactions[2].push_back("ACCOUNT2");
  transactions[2].push_back("100");

  transactions.push_back(vector<string>());
  transactions[3].push_back("4");
  transactions[3].push_back("SAVE");
  transactions[3].push_back("ACCOUNT3");
  transactions[3].push_back("500");

  transactions.push_back(vector<string>());
  transactions[4].push_back("3");
  transactions[4].push_back("WITHDRAW");
  transactions[4].push_back("ACCOUNT2");
  transactions[4].push_back("30");

  solution(snapshots, transactions);
}