#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string origin = "";
vector<string> v;
string ans = "";
bool isP[100];

void findOrigin(vector<string> &s) {
	for (int i = 1; i < s[0].length(); i++) {
		if (s[0].at(i) != s[1].at(i - 1)) {
			origin += s[1]; origin += s[0].at(N - 2);
			return;
		}
	}
	int cnt = 2 * ( N - 1 );
	origin = s[0]; origin += s[1].at(N - 2);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].length(); j++) {
			if (v[i][j] != origin[j]) {
				cnt--; break;
			}
		}
	}
	if (cnt < N - 1) origin = s[1]; origin += s[0].at(N - 2);
}

string classify(string s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s.at(i) != origin.at(i) || isP[len]) return "S";
	}
	isP[len] = true;
	return "P";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<string> parts;
	for (int i = 0; i < 2 * (N - 1); i++) {
		string s; cin >> s;
		v.push_back(s);
		if (s.length() == N - 1) parts.push_back(s);
	}
	findOrigin(parts);
	for (int i = 0; i < v.size(); i++) ans += classify(v[i]);
	cout << origin << "\n" << ans;
	return 0;
}

//brute force?
//원본 문자열을 만들고 나서 확인이 필요