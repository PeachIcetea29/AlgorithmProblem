#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define TARGET 100
#define WALL -1
using namespace std;

int tc, R, C;
int dr[4] = { -1,1 , 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int bfs(int arr[][102], bool keys[27]) {
	int ans = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	vector<vector<bool>> visited(R + 2, vector<bool>(C + 2, 0));
	visited[0][0] = true;
	while (!q.empty()) {
		int r = q.front().first; int c = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i]; int nc = c + dc[i];
			if (nr < 0 || nr > R + 1 || nc < 0 || nc > C + 1 || arr[nr][nc] == WALL) continue;
			if (!visited[nr][nc]) {
				if (arr[nr][nc] == TARGET) {
					ans++;
					arr[nr][nc] = 0;
				}
				else if (arr[nr][nc] > 26 && arr[nr][nc] <= 52 && !keys[arr[nr][nc]-26]) {
					keys[arr[nr][nc] - 26] = true;
					arr[nr][nc] = 0;
					visited.clear();
					visited.resize(R + 2, vector<bool>(C + 2, false));
					queue<pair<int, int>> nq;
					q = nq;
					q.push({ nr, nc });
					visited[nr][nc] = true;
					break;
				}
				else if (arr[nr][nc] > 0 && arr[nr][nc] <= 26 && !keys[arr[nr][nc]]) {
					continue;
				}
				q.push({ nr, nc });
				visited[nr][nc] = true;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> R >> C;
		bool keys[27] = { 0, };
		int arr[102][102] = { 0, };
		for (int i = 1; i <= R; i++) {
			string s; cin >> s;
			for (int j = 1; j <= C; j++) {
				if (s[j - 1] == '*') arr[i][j] = WALL;
				else if (s[j - 1] == '$') arr[i][j] = TARGET;
				else if (s[j - 1] >= 'A' && s[j - 1] <= 'Z') arr[i][j] = s[j - 1] - 'A' + 1;
				else if (s[j - 1] >= 'a' && s[j - 1] <= 'z') arr[i][j] = s[j - 1] - 'a' + 27;
			}
		}
		string s; cin >> s;
		if (s[0] != '0') {
			int len = s.length();
			for (int i = 0; i < len; i++) {
				keys[s[i] - 'a' + 1] = true;
			}
		}
		cout << bfs(arr, keys) << "\n";
	}
	return 0;
}

//BFS
//없는 KEY를 발견한 경우에만 다시 새롭게 BFS. 
//겉을 0으로 채워서 어느 입구에든 갈 수 있도록