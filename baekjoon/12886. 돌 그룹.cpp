#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v(3);
bool check[500][500];

void move(queue<vector<int>> &q, vector<int> &now, int m1, int m2, int d) {
	int n1 = now[m1] * 2; int n2 = now[m2] - now[m1]; int n3 = now[d];
	vector<int> nv = { n1, n2, n3 };
	sort(nv.begin(), nv.end());
	if (!check[nv[0]][nv[1]]) {
		check[nv[0]][nv[1]] = true;
		q.push(nv);
	}
}

int bfs() {
	int target = (v[0] + v[1] + v[2]) / 3;
	if (target * 3 != v[0] + v[1] + v[2]) return 0;
	queue<vector<int>> q;
	q.push(v);
	check[v[0]][v[1]] = true;
	while (!q.empty()) {
		vector<int> now = q.front(); q.pop();
		if (now[0] == now[1] && now[1] == now[2]) return 1;
		if (now[0] < now[1]) move(q, now, 0, 1, 2);
		if (now[0] < now[2]) move(q, now, 0, 2, 1);
		if (now[1] < now[2]) move(q, now, 1, 2, 0);
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &v[0], &v[1], &v[2]);
	sort(v.begin(), v.end());
	printf("%d", bfs());
	return 0;
}

//BFS
//두 그룹을 알면 나머지 한 그룹도 알 수 있으므로 두 그룹만 체크해도 됨
//거꾸로 출발하는 것도 가능