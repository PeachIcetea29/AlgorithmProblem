#include <stdio.h>

#define DIV 1000000000

int main() {
	int N, K; scanf("%d %d", &N, &K);
	long long d[201][201] = { 0, };
	for (int i = 0; i <= N; i++) d[1][i] = 1;

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= DIV;
			}
		}
	}
	printf("%d\n", d[K][N]);
	return 0;
}
//DP
//k-1개를 사용하여 만든 수에 나머지 ?값을 붙여줌
