#include <stdio.h>
#include <queue>

using namespace std;

#define START 1
#define END 100

int N, M;
int portal[101];
int visit[101];
queue<int> q;

void makePortal(int size) {
	for (int i = 0; i < size; i++) {
		int x, y; scanf("%d %d", &x, &y);
		portal[x] = y;
	}
}

void bfs() {
	q.push(START);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			if (next > END) break;
			if (!visit[next] || visit[now] + 1 < visit[next]) {
				visit[next] = visit[now] + 1;
				if (portal[next]) {
					if (!visit[portal[next]] || visit[now] + 1 < visit[portal[next]]){
						q.push(portal[next]);
						visit[portal[next]] = visit[now] + 1;
					}
				}
				else q.push(next);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	makePortal(N); makePortal(M);
	bfs();
	printf("%d", visit[100]);
	return 0;
}

//BFS
//이전보다 더 빠르게 갈 수 있는 경우, 새롭게 큐에 추가