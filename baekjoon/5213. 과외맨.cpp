#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tile {
	int l, r;
};

int N;
int d[500][500];
int numbering[500][500];
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
pair<int, int> route[500][500];
vector<vector<Tile>> TileMap;

void bfs(pair<int, int> p) {
	queue<pair<int, int>> q;
	q.push(p);
	d[p.first][p.second] = 0;
	while (!q.empty()) {
		int r = q.front().first; int c = q.front().second; q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i]; int nc = c + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (r % 2 == 0) {
				if (i == 1 || i == 3) continue;
				if ((i == 4 || i == 0) && nc == N - 1) continue;
				if (d[r][c] + 1 < d[nr][nc]) {
					if (i < 5 && TileMap[r][c].r == TileMap[nr][nc].l) {
						d[nr][nc] = d[r][c] + 1;
						q.push({ nr, nc });
						route[nr][nc] = { r,c };
					}
					else if (i >= 5 && TileMap[r][c].l == TileMap[nr][nc].r) {
						d[nr][nc] = d[r][c] + 1;
						q.push({ nr, nc });
						route[nr][nc] = { r,c };
					}
				}
			}
			else if (r % 2 == 1) {
				if (i == 5 || i == 7) continue;
				if (i == 2 && nc == N - 1) continue;
				if (d[r][c] + 1 < d[nr][nc]) {
					if ((i >= 1 && i <= 3) && TileMap[r][c].r == TileMap[nr][nc].l) {
						d[nr][nc] = d[r][c] + 1;
						q.push({ nr, nc });
						route[nr][nc] = { r,c };
					}
					else if ((i == 0 || i == 4 || i == 6) && TileMap[r][c].l == TileMap[nr][nc].r) {
						d[nr][nc] = d[r][c] + 1;
						q.push({ nr, nc });
						route[nr][nc] = { r,c };
					}
				}
			}
		}
	}
	int tr = N - 1; int tc = N - 1;
    if(N % 2 == 0) tc = N-2;
	while (d[tr][tc] == 2e9) {
		if (--tc < 0) {
			if (--tr % 2 == 0) tc = N - 1;
			else tc = N - 2;
		}
	}
	
	vector<int> ans;
	pair<int, int> temp = { tr,tc };
	do {
		ans.push_back(numbering[temp.first][temp.second]);
		temp = route[temp.first][temp.second];
	} while (temp.first != 0 || temp.second != 0);

	ans.push_back(1);
	cout << d[4][4] + 1 << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	TileMap.resize(N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - (i % 2); j++) {
			int l, r; cin >> l >> r;
			TileMap[i].push_back({ l, r });
			d[i][j] = 2e9;
			numbering[i][j] = ++cnt;
		}
	}
	bfs({ 0, 0 });
	return 0;
}

//BFS
//타일 크기 1*2를 하나의 단위로 쓰고자 구조체 활용
//리팩토링이 필요할듯..