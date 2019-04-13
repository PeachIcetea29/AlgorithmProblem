#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int R, C, N;
int arr[100][100];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void checkCluster() {
	bool visit[100][100] = { 0, };
	for (int c = 0; c < C; c++) {
		if (visit[R - 1][c] == true || arr[R - 1][c] == 0) continue;
		queue<pair<int, int>> q;
		q.push({ R - 1, c });
		visit[R - 1][c] = true;
		while (!q.empty()) {
			int r = q.front().first; int c = q.front().second; q.pop();
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k]; int nc = c + dc[k];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C || arr[nr][nc] == 0) continue;
				if (!visit[nr][nc]) {
					visit[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}
	}
	vector<pair<int, int>> target;
	for (int i = R - 1; i >= 0; i--) {
		for (int j = C - 1; j >= 0; j--) {
			if (!visit[i][j] && arr[i][j] == 1) {
				arr[i][j] = 0;
				target.push_back({ i, j });
			}
		}
	}
	if (target.empty()) return;
	bool isDown = true;
	int len = target.size();
	while (isDown) {
		for (int i = 0; i < len; i++) {
			int nr = target[i].first + 1;
			int nc = target[i].second;
			if (nr >= R || arr[nr][nc] == 1) {
				isDown = false; break;
			}
		}
		if (isDown) {
			for (int i = 0; i < len; i++) {
				target[i].first++;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		arr[target[i].first][target[i].second] = 1;
	}
}

void destroy(int turn, int h) {
	int a = (C - 1) * turn;
	while ((0 <= a && a < C) && !arr[R - h][a]) {
		if (turn == 0) a++;
		else a--;
	}
	if (0 <= a && a < C) {
		arr[R - h][a] = 0;
		checkCluster();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == 'x') arr[i][j] = 1;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		destroy(i % 2, n);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 0) cout << ".";
			else cout << "x";
		}
		cout << "\n";
	}
	return 0;
}

//Simulation
//땅에서 부터 클러스터를 체크
//클러스터를 내릴 수 있는지 확인하기 위해 기존 클러스터의 정보를 담아 두고 맵 상에서 모두 파괴.
//빈칸이 있는 곳 까지 클러스터의 정보에서 좌표를 증가시켜주며, 맨 마지막에 마킹하는 식으로 구현