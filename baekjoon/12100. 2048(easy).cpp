#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int order[5];
vector<vector<int>> arr;

void _sum(int row, int col, int dir, queue<int> &q, vector<vector<int>> &v) {
	while (!q.empty()) {
		int n = q.front(); q.pop();
		if (!q.empty() && n == q.front()) {
			n += q.front(); q.pop();
		}
		v[row][col] = n;
		ans = max(ans, n);
		row += dr[dir]; col += dc[dir];
	}
}

void pushing(int dir, vector<vector<int>> &result) {
	vector<vector<int>> v(N, vector<int>(N, 0));
	queue<int> q;
	if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (result[i][j]) q.push(result[i][j]);
			}
			_sum(i, 0, dir, q, v);
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (result[i][j]) q.push(result[i][j]);
			}
			_sum(i, N - 1, dir, q, v);
		}
	}
	else if (dir == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (result[j][i]) q.push(result[j][i]);
			}
			_sum(N - 1, i, dir, q, v);
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (result[j][i]) q.push(result[j][i]);
			}
			_sum(0, i, dir, q, v);
		}
	}
	result = v;
}

void dfs(int count) {
	if (count == 5) {
		vector<vector<int>> result(arr);
		for (int i = 0; i < 5; i++) {
			pushing(order[i], result);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		order[count] = i;
		dfs(count + 1);
	}
}

int main() {
	scanf("%d", &N);
	arr.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}

//Brute force
//Queue 이용