#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool used[26];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		used[s[i] - 'a'] = true;
		v.push_back(s[i] - 'a');
	}
	if (s.length() == 26) {
		vector<int> nextp(v);
		if (next_permutation(nextp.begin(), nextp.end())) {
			for (int i = 0; i < v.size(); i++) {
				ans += ('a' + nextp[i]);
				if (v[i] != nextp[i]) break;
			}
		}
		else ans = "-1";
	}
	else {
		ans = s;
		for (int i = 0; i < 26; i++) {
			if (!used[i]) {
				ans += ('a' + i);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

//순열을 이용한 풀이