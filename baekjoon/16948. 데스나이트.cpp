#include <cstdio>
#include <queue>

using namespace std;

struct status {
	int r, c, cnt;
};

int N;
int d[200][200];
int dr[6] = { -2,-2,0,0,2,2 };
int dc[6] = { -1,1,-2,2,-1,1 };
pair<int, int> start, target;

int bfs() {
	queue<status> q;
	q.push({ start.first, start.second, 0 });
	d[start.first][start.second] = 0;
	while (!q.empty()) {
		status now = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nr = now.r + dr[i]; int nc = now.c + dc[i]; int ncnt = now.cnt + 1 ;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (d[nr][nc] > ncnt) {
				d[nr][nc] = ncnt;
				q.push({ nr, nc , ncnt });
			}
		}
	}
	int result = d[target.first][target.second];
	return result != 2e9 ? result : -1;
}

int main() {
	scanf("%d", &N);
	scanf("%d %d %d %d", &start.first, &start.second, &target.first, &target.second);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			d[i][j] = 2e9;
		}
	}
	printf("%d", bfs());
	return 0;
}

//BFS
//진행 방향이 특이한 경우
//이동한 경로에 대해서 최소값을 가지고 있다가, 최소일 경우 갱신시켜줌