#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N, M, ans;
int arr[1000][1000];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int visit[1000][1000];
vector<pair<int, int>> v;
vector<int> counting(1, 0);

int bfs(int r, int c, int idx) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visit[r][c] = idx;
	int count = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.first + dr[i]; int nc = now.second + dc[i];
			if (nr >= 0 && nr < N && nc >= 0 && nc < M && arr[nr][nc] == 1) {
				if (!visit[nr][nc]) {
					visit[nr][nc] = idx;
					q.push({ nr,nc });
					count++;
				}
			}
		}
	}
	return count;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (!arr[i][j]) v.push_back({ i, j });
		}
	}
	int idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && !visit[i][j]) {
				counting.push_back(bfs(i, j, idx++));
			}
		}
	}
	int vlen = v.size();
	for (int i = 0; i < vlen; i++) {
		map<int, bool> used;
		int temp = 1;
		for (int j = 0; j < 4; j++) {
			int nr = v[i].first + dr[j]; int nc = v[i].second + dc[j];
			if (nr >= 0 && nr < N && nc >= 0 && nc < M && arr[nr][nc] == 1) {
				if (used.find(visit[nr][nc]) == used.end()) {
					temp += counting[visit[nr][nc]];
					used.insert({ visit[nr][nc], true });
				}
			}
		}
		ans = max(ans, temp);
	}
	printf("%d", ans);
	return 0;
}

//BFS로 먼저 같은 모양끼리 그룹화하고 크기를 저장
//이후 0인 지점을 탐색하여 미리 저장해둔 그룹과 크기를 이용하여 구함
//매번 0을 1로 바꾸면서 탐색하기에는 시간이 오래걸림. 그래서 한꺼번에 구해놓고 해야 함