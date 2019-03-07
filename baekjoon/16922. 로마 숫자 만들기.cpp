#include <stdio.h>

int N;
int d[21][1001];
int number[4] = { 1, 5, 10, 50 };

int main() {
	scanf("%d", &N);
	d[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int n = 0; n <= 1000; n++) {
			for (int j = 0; j < 4; j++) {
				if (d[i-1][n] && n + number[j] <= 1000) d[i][n + number[j]]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 1000; i++) {
		if (d[N][i]) ans++;
	}
	printf("%d", ans);
	return 0;
}

//DP
//i-1개를 사용하여 만든 수에 하나를 더함.