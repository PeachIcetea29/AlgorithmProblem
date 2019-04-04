#include <cstdio>

int N, M;
int ups, lefts, backs;

int main() {
	scanf("%d %d", &N, &M);
	ups = N * M;
	int arr[100][100] = { 0, };
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if( arr[i][j] > temp ) lefts += arr[i][j] - temp;
			temp = arr[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j][i] > temp) backs += arr[j][i] - temp;
			temp = arr[j][i];
		}
	}
	printf("%d", ups * 2 + lefts * 2 + backs * 2);
	return 0;
}

//brute force
//앞, 위, 옆에서 바라본 각각의 겉넓이 값의 두배 합