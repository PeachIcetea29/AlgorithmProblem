#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define WALL -1

using namespace std;

int R, C;

pair<int, int> robot, initP;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs(pair<int,int> p, int arr[][20], int d[][20][20], int idx) {
	queue<pair<int, int>> q;
	q.push(p);
	bool visited[20][20] = { 0, };
	visited[p.first][p.second] = true;
	while (!q.empty()) {
		int r = q.front().first; int c = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i]; int nc = c + dc[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || arr[nr][nc] == WALL) continue;
			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				d[idx][nr][nc] = d[idx][r][c] + 1;
				q.push({ nr,nc });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int ans = 2e9;
		cin >> C >> R; if (R == 0 && C == 0) break;

		int arr[20][20] = { 0, };
		int d[10][20][20] = {0, };
		vector<pair<int, int>> dirty;

		for (int i = 0; i < R; i++) {
			string s; cin >> s;
			for (int j = 0; j < C; j++) {
				if (s[j] == 'x') arr[i][j] = WALL;
				else if (s[j] == 'o') initP = { i, j };
				else if (s[j] == '*') dirty.push_back({ i, j });
			}
		}

		int dlen = dirty.size();
		vector<int> number;
		for (int i = 0; i < dlen; i++) {
			bfs(dirty[i], arr, d, i);
			number.push_back(i);
		}

		do {
			int temp = 0;
			robot = initP;
			for (int i = 0; i < dlen; i++) {
				if (d[number[i]][robot.first][robot.second] == 0) {
					ans = -1; break;
				}
				temp += d[number[i]][robot.first][robot.second];
				robot = { dirty[number[i]].first, dirty[number[i]].second };
			}
			if (ans > temp) ans = temp;
		} while (next_permutation(number.begin(), number.end()));
		cout << ans << "\n";
	}
	return 0;
}

//BFS, 순열
//매번 최단거리로 움직이도록 BFS를 하면 되지 않을까 생각했지만, 반례가 존재
//bfs로 모든 먼지 기준 최단거리를 탐색해놓고, 순열을 이용하여 모든 경우의수를 체크
//데이터 참조 https://icpc.iisf.or.jp/past-icpc/domestic2005/