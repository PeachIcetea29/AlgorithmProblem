#include <stdio.h>
#include <algorithm>

using namespace std;

int A, B, C, X, Y;

int main() {
	int ans = 0;
	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
	if (2 * C > A + B) ans = A * X + B * Y;
	else {
		int limit = min(X, Y);
		ans += limit * C * 2;
		X -= limit; Y -= limit;
		if (X > 0) {
			if (A > 2 * C) ans += X * (2 * C);
			else ans += X * A;
		}
		else if (Y > 0) {
			if (B > 2 * C) ans += Y * (2 * C);
			else ans += Y * B;
		}
	}
	printf("%d\n", ans);
	return 0;
}

//간단한 수학문제