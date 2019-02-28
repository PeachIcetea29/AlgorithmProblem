#include <iostream>
#include <string>

using namespace std;

int tc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> tc;
	int cnt = 1;
	while (tc--) {
		char ans;
		string s; cin >> s;
		int len = s.length();
		int count = 0;
		int sum = s[0] - '0';
		for (int i = 1; i < len; i++) {
			sum += s[i] - '0';
			count++;
			if (sum >= 10) {
				sum = (sum / 10) + (sum % 10);
				count++;
			}
		}

		if (count % 2 == 0) ans = 'B';
		else ans = 'A';
		cout << "#" << cnt++ << " " << ans << "\n";
	}
	return 0;
}