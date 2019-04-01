#include <iostream>
#include <string>

using namespace std;

int N, M;
int arr[50][50];
bool visit[50][50];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool dfs(int type, int r, int c, pair<int,int> prev) {
	if (visit[r][c]) return true;
	visit[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i]; int nc = c + dc[i];
		if (nr == prev.first && nc == prev.second) continue;
		if (nr >= 0 && nr < N && nc >= 0 && nc < M && arr[nr][nc] == type) {
			if (dfs(type, nr, nc, { r, c })) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	bool isPossible = false;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j] - 'A';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				if (dfs(arr[i][j], i, j, {i, j})) {
					isPossible = true; break;
				}
			}
		}
		if (isPossible) break;
	}
	if(isPossible) printf("Yes\n");
	else printf("No\n");
	return 0;
}

//DFS
//이미 방문했던 곳을 또 방문한다면 사이클이 존재한다는 것