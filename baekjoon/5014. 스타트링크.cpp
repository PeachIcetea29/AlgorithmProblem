#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int d[1000001];

void bfs() {
	queue<pair<int,int>> q;
	q.push({ S, 0 });
	d[S] = 0;
	while (!q.empty()) {
		int n = q.front().first; int cnt = q.front().second; q.pop();
		if (U != 0 && n + U <= F && cnt + 1 < d[n + U]) {
			d[n + U] = cnt + 1;
			q.push({ n + U, cnt + 1 });
		}
		if (D != 0 && n - D >= 1 && cnt + 1 < d[n - D]) {
			d[n - D] = cnt + 1;
			q.push({ n - D, cnt + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	for (int i = 1; i <= F; i++) {
		d[i] = 2e9;
	}
	bfs();
	if (d[G] != 2e9) cout << d[G];
	else cout << "use the stairs";
	
	return 0;
}

//BFS