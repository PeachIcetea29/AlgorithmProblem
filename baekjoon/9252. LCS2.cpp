#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[2];
int d[1001][1001];
string lcs[1001][1001];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> s[0] >> s[1];
	int len_s0 = s[0].length();
	int len_s1 = s[1].length();
	for (int i = 1; i <= len_s0; i++) {
		for (int j = 1; j <= len_s1; j++) {
			if (s[0][i-1] == s[1][j-1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
				lcs[i][j] = lcs[i - 1][j - 1] + s[0][i-1];
			}
			else {
				if (d[i][j - 1] > d[i - 1][j]) {
					d[i][j] = d[i][j - 1];
					lcs[i][j] = lcs[i][j - 1];
				}
				else {
					d[i][j] = d[i - 1][j];
					lcs[i][j] = lcs[i - 1][j];
				}
				
			}
		}
	}
	cout << d[len_s0][len_s1] << "\n" << lcs[len_s0][len_s1];
	return 0;
}

//DP problem