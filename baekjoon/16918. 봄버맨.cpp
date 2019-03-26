#include <iostream>
#include <vector>

using namespace std;

int R, C, N;
int arr[201][201];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void printArray() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if(arr[i][j] > 0) cout << 'O';
			else cout << '.';
		}
		cout << "\n";
	}
}

void bomb(vector<pair<int, int>>& v) {
	int len = v.size();
	for (int i = 0; i < len; i++) {
		int r = v[i].first; int c = v[i].second;
		arr[r][c] = 0;
		for (int j = 0; j < 4; j++) {
			int next_r = r + dr[j]; int next_c = c + dc[j];
			if (next_r >= 0 && next_r < R && next_c >= 0 && next_c < C) arr[next_r][next_c] = 0;
		}
	}
}

void solve() {
	int cnt = 1;
	while (N--) {
		vector<pair<int, int>> v;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] > 0) arr[i][j]--;
				if (cnt % 2 == 0 && arr[i][j] <= 0) {
					arr[i][j] = 3; continue;
				}
				if (arr[i][j] == 0) v.push_back({ i, j });
			}
		}
		cnt++;
		bomb(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			if (c == 'O') arr[i][j] = 3;
			else arr[i][j] = -1;
		}
	}
	solve();
	printArray();
	return 0;
}

//simulation 