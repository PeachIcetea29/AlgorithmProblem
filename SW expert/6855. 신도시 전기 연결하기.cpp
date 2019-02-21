#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	int cnt = 1;
	while (tc--) {
		int ans = 0;
		int N, K; scanf("%d %d", &N, &K);
		vector<int> home(N);
		vector<int> distance;
		scanf("%d", &home[0]);
		for (int i = 1; i < N; i++) {
			scanf("%d", &home[i]);
			distance.push_back(home[i] - home[i - 1]);
		}
		sort(distance.begin(), distance.end());
		for (int i = distance.size() - K; i >= 0; i--) ans += distance[i];
		printf("#%d %d\n", cnt++, ans);
	}
	return 0;
}

//수학적으로 접근