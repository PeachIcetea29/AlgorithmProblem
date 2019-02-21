#include <stdio.h>

int N, K;
int arr[5000000];
int ans;

void swap(int* n1, int* n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int searching(int begin, int end) {
	int pivot = begin;
	int i = pivot + 1;
	int j = end;
	while (true) {
		while (i <= end && arr[i] <= arr[pivot]) i++;
		while (j >= begin && arr[j] > arr[pivot]) j--;

		if (i > j) {
			swap(&arr[j], &arr[pivot]);
			if (j == K - 1) {
				return arr[j];
			}
			else if (j < K - 1) {
				searching(j + 1, end);
			}
			else {
				searching(begin,j - 1);
			}
			break;
		}
		else {
			swap(&arr[i], &arr[j]);
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	printf("%d", searching(0, N-1));
	return 0;
}