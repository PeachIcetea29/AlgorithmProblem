#include <cstdio>

long long d[30][30];

long long func(int w, int h) {
	if (w == 0 || (w == 1 && h == 0)) return 1;

	if (d[w][h]) return d[w][h];

	d[w][h] += func(w - 1, h + 1);
	if(h > 0) d[w][h] += func(w, h - 1);
	return d[w][h];
}

int main() {
	while (true) {
		int N; scanf("%d", &N);
		if (N == 0) break;
		printf("%lld\n", func(N - 1, 1));
	}
	return 0;
}

//DP
//알약의 남은 개수에 따라 재귀로 반복하며 경우의 수를 구함