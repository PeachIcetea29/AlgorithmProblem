#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct board {
	int arr[4][5][5];
};

struct cursor {
	int r, c, h;
};

board b[5];
int dr[4] = { -1 ,1 , 0 ,0 };
int dc[4] = { 0, 0, -1, 1 };
int dh[2] = { 1, -1 };
vector<int> order(5);
vector<int> aorder(5);
int ans = 2e9;

void bfs() {
	queue<cursor> q;
	q.push({0, 0, 0});
	int visited[5][5][5] = { 0, };
	visited[0][0][0] = 1;
	while (!q.empty()) {
		cursor now = q.front(); q.pop();
		int r = now.r; int c = now.c; int h = now.h;
		if (h == 4 && r == 4 && c == 4) {
			ans = min(ans, visited[4][4][4] - 1);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i]; int nc = c + dc[i];
			if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
			if (b[order[h]].arr[aorder[h]][nr][nc] == 0) continue;
			if (!visited[h][nr][nc]) {
				visited[h][nr][nc] = visited[h][r][c] + 1;
				q.push({ nr, nc, h });
			}
		}
		for (int i = 0; i < 2; i++) {
			int nh = h + dh[i];
			if (nh < 0 || nh >= 5 || b[order[nh]].arr[aorder[nh]][r][c] == 0) continue;
			if (!visited[nh][r][c]) {
				visited[nh][r][c] = visited[h][r][c] + 1;
				q.push({ r, c, nh });
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		if (b[order[0]].arr[aorder[0]][0][0] && b[order[4]].arr[aorder[4]][4][4]) {
			bfs();
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		aorder[cnt] = i;
		dfs(cnt + 1);
	}
}

void rotate(int idx) {
	for (int cnt = 0; cnt < 3; cnt++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				b[idx].arr[cnt + 1][j][4 - i] = b[idx].arr[cnt][i][j];
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				scanf("%d", &b[i].arr[0][r][c]);
			}
		}
		rotate(i);
	}
	for (int i = 0; i < 5; i++) order[i] = i;

	do {
		dfs(0);
		if (ans == 12) break;
	} while (next_permutation(order.begin(), order.end()));

	if (ans == 2e9) ans = -1;
	printf("%d", ans);
	return 0;
}

//순열, 재귀, BFS
//순열을 이용해서 판의 순서를, 재귀를 이용해서 회전의 상태를 모두 체크. 이후 BFS로 길 탐색