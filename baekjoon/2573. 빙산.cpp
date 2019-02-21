#include <stdio.h>
#include <list>
#include <queue>

using namespace std;

struct iceberg {
	int r, c, h;
};

int N, M;
int arr[300][300];
int dr[4] = {-1, 1, 0 ,0 };
int dc[4] = {0, 0, -1, 1};
list<iceberg> icebergList;
int ans;

bool isPartition() {
	if (!icebergList.size()) {
		ans = 0; return true;
	}
	bool visit[300][300] = { 0, };
	queue<pair<int, int>> q;
	list<iceberg>::iterator iter = icebergList.begin();
	q.push({ iter->r, iter->c });
	visit[iter->r][iter->c] = true;
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int next_r = p.first + dr[i]; int next_c = p.second + dc[i];
			bool isRange = next_r >= 0 && next_r < N && next_c >= 0 && next_c < M;
			if (isRange && !visit[next_r][next_c] && arr[next_r][next_c]) {
				q.push({ next_r, next_c });
				visit[next_r][next_c] = true;
			}
		}
	}
	for (iter; iter != icebergList.end(); iter++) {
		if (!visit[iter->r][iter->c]) return true;
	}
	return false;
}

void melt() {
	ans++;
	list<iceberg>::iterator iter;
	for (iter = icebergList.begin(); iter != icebergList.end(); iter++) {
		int melting = 0;
		for (int i = 0; i < 4; i++) {
			int next_r = iter->r + dr[i]; int next_c = iter->c + dc[i];
			bool isRange = next_r >= 0 && next_r < N && next_c >= 0 && next_c < M;
			if (isRange && arr[next_r][next_c] == 0) melting++;
		}
		if (iter->h < melting) iter->h = 0;
		else iter->h -= melting;
	}

	for (iter = icebergList.begin(); iter != icebergList.end(); ) {
		arr[iter->r][iter->c] = iter->h;
		if (iter->h == 0) iter = icebergList.erase(iter);
		else iter++;
	}

	if (isPartition()) return;
	else melt();
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) icebergList.push_back({ i, j, arr[i][j] });
		}
	}
	melt();
	printf("%d", ans);
}

//bfs , dfs