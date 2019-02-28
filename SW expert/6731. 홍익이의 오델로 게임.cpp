#include <stdio.h>

int tc, N;

int main() {
	scanf("%d", &tc);
	int cnt = 1;
	while (tc--) {
		int ans = 0;
		scanf("%d", &N);
		bool map[1001][1001];
		int row[1001] = { 0, };
		int col[1001] = { 0, };
		for (int i = 0; i < N; i++) {
			char s[1001]; scanf("%s", s);
			for (int j = 0; j < N; j++) {
				if (s[j] == 'B') {
					map[i][j] = true;
					row[i]++;
					col[j]++;
				}
				else {
					map[i][j] = false;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int sum = row[i] + col[j];
				if (map[i][j] == true) sum--;
				if (sum % 2 != 0) ans++;
			}
		}
		printf("#%d %d\n", cnt++, ans);
	}

	return 0;
}

//패턴을 찾는 문제
//조금이라도 더 최적화할 것
//char 비교는 시간이 조금 더 걸린다는 것