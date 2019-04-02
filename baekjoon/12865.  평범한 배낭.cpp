#include <stdio.h>
#include <algorithm>

using namespace std;

int d[101][100001];
int val[101];
int weight[101];

int main() {
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &weight[i], &val[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - weight[i] >= 0) d[i][j] = max(d[i - 1][j], d[i - 1][j - weight[i]] + val[i]);
			else d[i][j] = d[i - 1][j];
		}
	}
	printf("%d", d[N][K]);
	return 0;
}

//DP, Knapsack