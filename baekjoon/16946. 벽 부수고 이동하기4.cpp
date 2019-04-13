#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

int N, M;
int arr[1000][1000];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1 ,1 };
vector<int> cluster(2);
vector<pair<int, int>> v;

void bfs(pair<int,int> start, int idx) {
	queue<pair<int, int>> q;
	q.push(start);
	arr[start.first][start.second] = idx;
	int cnt = 1;
	while (!q.empty()) {
		int r = q.front().first; int c = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i]; int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || arr[nr][nc] == 1) continue;
			if (!arr[nr][nc]) {
				arr[nr][nc] = idx; cnt++;
				q.push({ nr,nc });
			}
		}
	}
	cluster.push_back(cnt);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
			if (!arr[i][j]) v.push_back({ i,j });

		}
	}
	int vlen = v.size(); int idx = 2;
	for (int i = 0; i < vlen; i++) {
		if (!arr[v[i].first][v[i].second]) bfs(v[i], idx++);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				set<int> chk;
				int cnt = 1;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k]; int nc = j + dc[k];
					if (nr < 0 || nr >= N || nc < 0 || nc >= M || arr[nr][nc] == 1) continue;
					int id = arr[nr][nc];
					if (id > 1) {
						if (chk.find(id) == chk.end()) {
							chk.insert({id});
							cnt += cluster[id];
						}
					}
				}
				printf("%d", cnt%10);
			}
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
//BFS
//0의 갯수를 미리 구해놓고, 벽을 없앨 때 구해놓은 수를 더하며 값을 구함