#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define STAR 1

struct cross {
	int r, c, size;
};

int N, M;
int arr[100][100];
bool visit[100][100];
int dr[4] = { -1, 1, 0 , 0 };
int dc[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> v;
vector<cross> ans;

void checkCross(int r, int c) {
	int cnt = 1;
	bool isCross = true;
	while(isCross) {
		vector<pair<int, int>> marking;
		marking.push_back({ r,c });
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i] * cnt; int nc = c + dc[i] * cnt;
			if (nr < 0 || nr > N - 1 || nc < 0 || nc > M - 1 || arr[nr][nc] != STAR) {
				isCross = false; cnt--;
				break;
			}
			marking.push_back({ nr, nc });
		}
		if (isCross) {
			for (int i = 0; i < 5; i++) visit[marking[i].first][marking[i].second] = true;
			cnt++;
		}
	}
	if (cnt) ans.push_back({ r+1, c+1, cnt });
}

bool canMake() {
	int len = v.size();
	for (int i = 0; i < len; i++) {
		if (!visit[v[i].first][v[i].second]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '*') {
				arr[i][j] = STAR;
				v.push_back({ i, j });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) checkCross(v[i].first, v[i].second);
	if (canMake()) {
		int csize = ans.size();
		cout << csize << "\n";
		for (int i = 0; i < csize; i++) {
			cout << ans[i].r << " " << ans[i].c << " " << ans[i].size << "\n";
		}
	}
	else cout << "-1";

	return 0;
}

//brute force