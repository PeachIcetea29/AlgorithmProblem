#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define SHEEP 1
#define WOLF 2

int R, C;
int arr[250][250];
bool visit[250][250];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int sheep, wolf;

void bfs(pair<int,int> p) {
	queue<pair<int, int>> q;
	q.push(p);
	visit[p.first][p.second] = true;
	int scnt = 0;
	int wcnt = 0;
	if (arr[p.first][p.second] == WOLF) wcnt++;
	else if (arr[p.first][p.second] == SHEEP) scnt++;

	while (!q.empty()) {
		int r = q.front().first; int c = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i]; int nc = c + dc[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || arr[nr][nc] == -1) continue;
			if (!visit[nr][nc]) {
				if (arr[nr][nc] == SHEEP) scnt++;
				else if (arr[nr][nc] == WOLF) wcnt++;
				visit[nr][nc] = true;
				q.push({ nr,nc });
			}
		}
	}
	if (scnt > wcnt) sheep += scnt;
	else wolf += wcnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '#') arr[i][j] = -1;
			else if (s[j] == 'o') arr[i][j] = SHEEP;
			else if (s[j] == 'v') arr[i][j] = WOLF;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visit[i][j] && arr[i][j] != -1) bfs({i, j});
		}
	}
	cout << sheep << " " << wolf;
	return 0;
}

//BFS