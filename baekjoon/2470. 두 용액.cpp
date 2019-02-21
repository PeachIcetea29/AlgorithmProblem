#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[100000];

int abs(int n) {
	return n > 0 ? n : -n;
}

int main() {
	scanf("%d" , &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	
	int i = 0; 
	int j = N - 1;
	int value = 2e9+1;
	int ans[2] = { 0, };
	while (i < j) {
		if (value > abs(arr[i] + arr[j])) {
			value = abs(arr[i] + arr[j]);
			if (arr[i] > arr[j]) {
				ans[0] = arr[j]; ans[1] = arr[i];
			}
			else {
				ans[0] = arr[i]; ans[1] = arr[j];
			}
		}

		if (i + 1 < j  && arr[i + 1] + arr[j] < value) i++;
		else if (j - 1 > i && arr[j - 1] + arr[i] < value) j--;
		else break;
	}
	printf("%d %d", ans[0], ans[1]);
	return 0;
}

//sorting, two pointer