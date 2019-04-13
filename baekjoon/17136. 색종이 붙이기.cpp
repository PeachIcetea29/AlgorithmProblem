#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N = 10;
int arr[10][10];
int cnt[6] = { 0, 5, 5, 5, 5, 5 };
int ans = 2e9;
vector<pair<int, int>> target;

void fill(int i, int j, int size, int val) {
	for (int r = i; r < i + size; r++) {
		for (int c = j; c < j + size; c++) {
			arr[r][c] = val;
		}
	}
}

bool check(int i, int j, int size) {
	if (i + size > N || j + size > N) return false;
	for (int r = i; r < i + size; r++) {
		for (int c = j; c < j + size; c++) {
			if (arr[r][c] == 0) return false;
		}
	}
	return true;
}

void dfs(int used) {
	int tlen = target.size();
	bool isFind = false;
	int tr, tc;
	for (int i = 0; i < tlen; i++) {
		if (arr[target[i].first][target[i].second]) {
			isFind = true; 
			tr = target[i].first; tc = target[i].second;
			break;
		}
	}
	if (!isFind) {
		ans = min(ans, used);
		return;
	}
	for (int i = 1; i <= 5; i++) {
		if (cnt[i] == 0) continue;
		if (!check(tr, tc, i)) return;
		cnt[i]--;
		fill(tr, tc, i, 0);
		dfs(used + 1);
		fill(tr, tc, i, 1);
		cnt[i]++;
	}
}

int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) target.push_back({ i, j });
		}
	}
	dfs(0);
	if (ans == 2e9) ans = -1;
	printf("%d", ans);
	return 0;
}

//Brute force
//DFS를 이용하여 가능한 색종이 사용 순서를 모두 탐색.
//전역변수에 값을 덮어씌웠다가 되돌리는 식으로 사용.
//처음엔 큰 색종이부터 붙이면 되지 않을까 잘못생각.
//이후 색종이 종류에 따라 순열로 순서를 바꿔가며 붙이면 되지 않을까 잘못생각.