#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


using namespace std;



int main3() {
	int N;

	vector<string> inputs;

	unordered_set<string> a;
	unordered_map<string, int> cnt;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		inputs.push_back(temp);

		a.clear();

		for (int j = 0; j < inputs[i].size(); ++j) {
			string cur;
			for (int k = j; k < inputs[i].size(); ++k) {
				cur.push_back(inputs[i][k]);
				a.insert(cur);
			}
		}

		for (const string& now : a) {
			cnt[now]++;
		}
	}

	int sol = 0;
	for (auto& now : inputs) {
		sol += cnt[now];
	}

	cout << sol - N << endl;
	return 0;
}