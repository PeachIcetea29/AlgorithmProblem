#include <stdio.h>
#include <queue>

#define MAX_X 500000

using namespace std;

int N, K;
queue<int> q;
int visit[2][MAX_X+1];

int bfs() {
	for (int time = 0; ;) {
		if (K > MAX_X) return -1;
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int now = q.front(); q.pop();
			if (K == now) return time;
			int nextTime = time + 1;
			if (now - 1 >= 0 && !visit[nextTime % 2][now - 1]) {
				q.push(now - 1); visit[nextTime % 2][now - 1] = nextTime;
			}
			if (now + 1 <= MAX_X && !visit[nextTime % 2][now + 1]) {
				q.push(now + 1); visit[nextTime % 2][now + 1] = nextTime;
			}
			if (now * 2 <= MAX_X && !visit[nextTime % 2][now * 2]) {
				q.push(now * 2); visit[nextTime % 2][now * 2] = nextTime;
			}
		}
		if (visit[time % 2][K]) return time;
		K += ++time;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	q.push(N);
	printf("%d", bfs());
	return 0;
}

//BFS
//짝수초와 홀수초 구분