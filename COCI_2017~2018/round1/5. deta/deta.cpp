#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <utility>
using namespace std;

auto comp = [](const pair<int, int> & a, const pair<int, int> & b) { 
	if (a.first < b.first) return true;
	else if (a.first == b.first && a.second > b.second) return true;
	else return false;
};

set<pair<int, int>, decltype(comp)> statements(comp);
int N, Q;



int main() {

	cin >> N >> Q;
	
	for (int i = 0; i < Q; i++) {
		char mode;
		int station, child_num;
		cin >> mode;
		cin >> station >> child_num;

		if (mode == 'M') {
			cout << "insert";
			statements.insert(make_pair(station, child_num));
			continue;
		}

	}

	for (auto iter = statements.begin(); iter != statements.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
}