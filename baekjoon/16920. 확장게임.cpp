#include <iostream>
#include <string>
#include <queue>

using namespace std;

enum { WALL = -1, EMPTY };

struct castle {
	int r, c, p;
};

int N, M, P;
int arr[1000][1000];
int dist[10];
int cnt[10];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
queue<castle> player[10];

void bfs() {
	while (true) {
		bool isFinish = true;
		for (int i = 1; i <= P; i++) {
			for (int j = 0; j < dist[i]; j++) {
				bool cantgo = true;
				int qsize = player[i].size();
				while (qsize--) {
					int r = player[i].front().r; int c = player[i].front().c; player[i].pop();
					for (int k = 0; k < 4; k++) {
						int next_r = r + dr[k]; int next_c = c + dc[k];
						if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) {
							if (arr[next_r][next_c] == EMPTY) {
								isFinish = false;
								cantgo = false;
								arr[next_r][next_c] = i;
								cnt[i]++;
								player[i].push({ next_r, next_c, i });
							}
						}
					}
				}
				if (cantgo) break;
			}
		}
		if (isFinish) break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> dist[i];

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '.') arr[i][j] = EMPTY;
			else if (s[j] == '#') arr[i][j] = WALL; 
			else {
				arr[i][j] = s[j] - '0';
				player[s[j] - '0'].push({ i, j , s[j] - '0' });
				cnt[s[j] - '0']++; 
			}
		}
	}
	bfs();
	for (int i = 1; i <= P; i++) cout << cnt[i] << " ";
	return 0;
}

//최적화하는데 다른사람의 코드를 참조함
//BFS
//플레이어의 턴을 구현하는 것을 각 큐로 나눠서 구현 하는 것이 편리
//적절한 플래그 사용
//큐에 들어있는 성이 1씩 상하좌우로 이동하는 것을 distance만큼 반복한다고 생각