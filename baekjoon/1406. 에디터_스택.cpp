#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> lefts;
stack<char> rights;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string original; cin >> original;
	for (int i = 0; i < original.length(); i++) {
		lefts.push(original[i]);
	}
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char command; cin >> command;
		if (command == 'P') {
			char word; cin >> word;
			lefts.push(word);
		}
		else if (command == 'L') {
			if (lefts.empty()) continue;
			rights.push(lefts.top()); lefts.pop();
		}
		else if (command == 'D') {
			if (rights.empty()) continue;
			lefts.push(rights.top()); rights.pop();
		}
		else if (command == 'B') {
			if (lefts.empty()) continue;
			lefts.pop();
		}
	}
	int len = lefts.size();
	string ans; ans.resize(len);
	int index = len - 1;
	while(!lefts.empty()) {
		ans[index--] = lefts.top(); lefts.pop();
	}
	while(!rights.empty()){
		ans += rights.top(); rights.pop();
	}
	cout << ans;
	return 0;
}

//스택을 활용한 풀이