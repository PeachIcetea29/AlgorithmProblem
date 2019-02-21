#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int d[101][10001];
int memory[101];
int cost[101];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &memory[i]);
	for (int i = 1; i <= N; i++) scanf("%d", &cost[i]);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j - cost[i] >= 0) d[i][j] = max(d[i - 1][j], d[i - 1][j - cost[i]] + memory[i]);
			else d[i][j] = d[i - 1][j];
		}
	}
	int ans = 0;

	for (ans; ans <= 10000; ans++) {
		if (d[N][ans] >= M) break;
	}

	printf("%d\n", ans);
	return 0;
}

//DP - Knapsack problem