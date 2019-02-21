#include <stdio.h>

int N, limit, ans;
int arr[10000];

void bs(int L, int R) {
	if (L > R) return;
	int mid = (L + R) / 2;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i] > mid) sum += mid;
		else sum += arr[i];
	}

	if (sum <= limit) {
		ans = mid;
		bs(mid + 1, R);
	}
	else bs(L, mid - 1);
}

int main() {
	scanf("%d", &N);
	int R = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (R < arr[i]) R = arr[i];
	}
	scanf("%d", &limit);
	bs(0, R);
	printf("%d", ans);
	return 0;
}

//binary search
//범위 주의