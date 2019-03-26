#include <stdio.h>

enum { hori, diago, verti };

int N;
int arr[32][32];
long long d[32][32][3];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	d[0][1][hori] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j][hori] && j + 1 < N && !arr[i][j + 1]) {
				d[i][j + 1][hori] += d[i][j][hori];
				if (i + 1 < N && !arr[i + 1][j] && !arr[i + 1][j + 1]) d[i + 1][j + 1][diago] += d[i][j][hori];
			}
			if (d[i][j][verti] && i + 1 < N && !arr[i + 1][j]) {
				d[i + 1][j][verti] += d[i][j][verti];
				if (j + 1 < N && !arr[i][j + 1] && !arr[i + 1][j + 1]) d[i + 1][j + 1][diago] += d[i][j][verti];
			}
			if (d[i][j][diago]) {
				if (j + 1 < N && !arr[i][j + 1]) d[i][j + 1][hori] += d[i][j][diago];
				if (i + 1 < N && !arr[i + 1][j]) d[i + 1][j][verti] += d[i][j][diago];
				if (i + 1 < N && j + 1 < N && !(arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1])) d[i + 1][j + 1][diago] += d[i][j][diago];
			}
		}
	}
	printf("%lld", d[N-1][N-1][hori] + d[N-1][N-1][diago] + d[N-1][N-1][verti]);
	return 0;
}

//brute force?
//점이 이동한다고 생각하기