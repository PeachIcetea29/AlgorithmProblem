#include <stdio.h>
#include <deque>

using namespace std;

int N, M, R;
int arr[300][300];

int main() {
	scanf("%d %d %d", &N ,&M, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	pair<int, int> p1 = { 0, 0 };
	pair<int, int> p2 = { N - 1, M - 1 };
	while (p1.first < p2.first && p1.second < p2.second) {
		int maxCount = (p2.first - p1.first + 1) * 2 + (p2.second - p1.second + 1) * 2 - 4;
		int newR = R % maxCount;
		deque<int> d;
		
		if (newR == 0) {
			p1.first++; p1.second++; p2.first--; p2.second--;
			continue;
		}
		int i = p1.first; int j = p1.second;
		
		while (i != p2.first) d.push_back(arr[i++][j]);
		while (j != p2.second) d.push_back(arr[i][j++]);
		while (i != p1.first) d.push_back(arr[i--][j]);
		while (j != p1.second) d.push_back(arr[i][j--]);

		for (int r = 0; r < newR; r++) {
			int temp = d.back(); d.pop_back();
			d.push_front(temp);
		}

		i = p1.first; j = p1.second;
		while (i != p2.first) {
			arr[i++][j] = d.front(); d.pop_front();
		}
		while (j != p2.second) {
			arr[i][j++] = d.front(); d.pop_front();
		}
		while (i != p1.first) {
			arr[i--][j] = d.front(); d.pop_front();
		}
		while (j != p1.second) {
			arr[i][j--] = d.front(); d.pop_front();
		}
		p1.first++; p1.second++; p2.first--; p2.second--;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}