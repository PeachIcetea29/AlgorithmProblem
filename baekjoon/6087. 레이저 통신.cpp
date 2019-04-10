#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct status {
	int r, c, cnt, dir;
};
int R, C;
int arr[100][100];
int d[100][100];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> p;

int bfs() {
	queue<status> q;
	for (int i = 0; i < 4; i++) q.push({ p[0].first, p[0].second, 0, i });
	d[p[0].first][p[0].second] = 0;
	while (!q.empty()) {
		status now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i]; int nc = now.c + dc[i]; 
            int ncnt = now.cnt + (i != now.dir);
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || arr[nr][nc] == -1) continue;
			if (d[nr][nc] >= ncnt) {
                d[nr][nc] = ncnt;
				q.push({ nr, nc, ncnt, i });
			}
		}
	}
	return d[p[1].first][p[1].second];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '*') arr[i][j] = -1;
			else if (s[j] == 'C') {
				arr[i][j] = 1; p.push_back({ i, j });
			}
			d[i][j] = 2e9;
		}
	}
	cout << bfs();
	return 0;
}