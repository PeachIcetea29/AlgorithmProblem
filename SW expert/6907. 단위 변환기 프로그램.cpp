#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<string, int> si;

string prefix[20] = { "yotta", "zetta", "exa", "peta", "tera", "giga", "mega",
	"kilo", "hecto", "deca", "deci", "centi", "milli", "micro", "nano", "pico", "femto",
	"ato", "zepto", "yocto" };
int prefix_n[20] = { 24, 21, 18, 15, 12, 9, 6, 3, 2, 1, -1, -2, -3,
	-6, -9, -12, -15, -18, -21, -24};

vector<string> convert(vector<string> original) {
	vector<string> after;
	string ns;
	string number("10^");
	int len = original[0].size();
	int size = original.size();
	int digit;
	if (original[0][0] == '0') {
		digit = 2;
		for (digit; original[0][digit] == '0'; digit++);

		ns += original[0][digit]; 
		if(digit != len-1 ) ns += ".";
		
		for (int i = digit + 1; i < len; i++) {
			ns += original[0][i];
		}

		digit = -digit + 1;
	}
	else {
		digit = 1;
		for (digit; digit < len && original[0][digit] != '.'; digit++);
		ns += original[0][0]; ns += ".";
		for (int i = 1; i < len; i++) {
			if (original[0][i] == '.') continue;
			ns += original[0][i];
		}

		digit -= 1;
	}
	if (size == 3) digit += si[original[1]];
	number.append(to_string(digit));
	after.push_back(ns);
	after.push_back(number);
	after.push_back(original[size - 1]);
	return after;
}

void setMap() {
	for (int i = 0; i < 20; i++) {
		si.insert(make_pair(prefix[i], prefix_n[i]));
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	int digit = 1;
	string buffer; getline(cin, buffer);
	setMap();
	while (tc--) {
		string s; getline(cin, s);
		istringstream iss(s);
		string token; vector<string> original;
		while (getline(iss, token, ' ')) {
			original.push_back(token);
		}
		vector<string> ans = convert(original);
		cout << "#" << digit++ << " " << ans[0] << " * " << ans[1] << " " << ans[2] << "\n";
	}
	return 0;
}

//String parsing problem
//개행문자가 버퍼에 남는 것 유의
//맵 사용