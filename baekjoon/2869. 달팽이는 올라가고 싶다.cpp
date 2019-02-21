#include <stdio.h>
#include <algorithm>

using namespace std;

int A, B, V;
int ans;

void bs(int L, int R) {
	int middle = (L + R) / 2;
	if (L > R) {
		return;
	}
	if ((A - B) * middle + A < V) {
		bs(middle+1, R);
	}
	else {
		ans = middle;
		bs(L, middle-1);
	}
}

int main() {
	scanf("%d %d %d", &A, &B, &V);
	bs(0, V);
	printf("%d\n", ans+1);
	return 0;
}

//최대와 최소를 잘 구분할 것