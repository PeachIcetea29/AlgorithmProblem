#include <cstdio>

long long d[101][21];
int arr[101];

int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	d[1][arr[1]] = 1;
	for (int i = 2; i <= N - 1; i++) {
		for (int n = 0; n <= 20; n++) {
			if (d[i-1][n]) {
				if (n - arr[i] >= 0) d[i][n - arr[i]] += d[i-1][n];
				if (n + arr[i] <= 20) d[i][n + arr[i]] += d[i-1][n];
			}
		}
	}
	printf("%lld", d[N-1][arr[N]]);
	return 0;
}

//DP
//i-1개를 사용해서 만든 수에 n번째 수를 빼거나 더해서 얻을 수 있는지