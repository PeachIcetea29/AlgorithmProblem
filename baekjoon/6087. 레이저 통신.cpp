#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct status {
	int r, c, dir, k, time;
};

int N, M, K;
pair<int, int> start, target;
int arr[1001][1001];
int d[1001][1001];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int bfs() {
	queue<status> q;
	q.push({ start.first, start.second, -1, 0, 0 });
	d[start.first][start.second] = 0;
	while (!q.empty()) {
		status now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i]; int nc = now.c + dc[i];
			int nk = now.k + 1; int ntime = now.time;
			if (nr < 1 || nr > N || nc < 1 || nc > M || arr[nr][nc]) continue;
			if (nk > K || i != now.dir) {
				nk = 1; ntime++;
			}
			if (d[nr][nc] > ntime) {
				q.push({ nr, nc, i, nk, ntime });
				d[nr][nc] = ntime;
			}
		}
	}
	int result = d[target.first][target.second];
	return result != 2e9 ? result : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 1; j <= M; j++) {
			d[i][j] = 2e9;
			if (s[j - 1] == '#') arr[i][j] = 1;
		}
	}
	cin >> start.first >> start.second >> target.first >> target.second;
	cout << bfs();
	return 0;
}