#include <stdio.h>
#include <math.h>

using namespace std;

int check(long long target) {
	int cnt = 0;
	while (true) {
		if (target == 2) break;

		bool isSqrt = false;
		long long sqrtTarget = (long long)sqrt(target);
		if (target == sqrtTarget * sqrtTarget) isSqrt = true;
		if (isSqrt) {
			target = sqrtTarget; cnt++;
		} 
		else {
			long long temp =  sqrtTarget + 1;
			cnt += (temp * temp) - target;
			target = temp * temp;
		}
	}
	return cnt;
}

int main() {
	int tc; scanf("%d", &tc);
	int cnt = 1;
	while (tc--) {
		int ans = 0;
		long long N; scanf("%lld", &N);
		printf("#%d %d\n", cnt++, check(N));
	}
	return 0;
}

//제곱수인지를 어떻게 판단 할 것인지
//범위 주의 ! 
//int형 자료를 곱했을 때, 범위가 int가 넘어가면 이상한 값이 입력되기에 long long으로 해준 것