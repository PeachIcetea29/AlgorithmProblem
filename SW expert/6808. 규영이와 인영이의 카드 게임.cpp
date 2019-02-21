#include <stdio.h>

int win, lose;
int ksum, isum;
int kyuYoung[9];
int inYoung[9];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(int depth, int n, int r) {
	for (int i = depth; i < n; i++) {

		swap(&inYoung[i], &inYoung[depth]);

		int temp = kyuYoung[depth] + inYoung[depth];
		int status = 0;
		if (kyuYoung[depth] > inYoung[depth]) {
			ksum += temp; status = 1;
		}
		else {
			isum += temp; status = 2;
		} 

		if (depth + 1 == r) {
			if (ksum > isum) win++;
			else lose++;
		}
		else permutation(depth+1, n, r);

		swap(&inYoung[i], &inYoung[depth]);
		if (status == 1) ksum -= temp;
		else if (status == 2) isum -= temp;

	}
}

int main() {
	int tc; scanf("%d", &tc);
	int cnt = 1;
	while (tc--) {
		win = 0; lose = 0; ksum = 0; isum = 0;
		bool number[19] = { 0, };
		int icnt = 0;
		for (int i = 0; i < 9; i++) {
			scanf("%d", &kyuYoung[i]);
			number[kyuYoung[i]] = true;
		}
		for (int i = 1; i <= 18; i++) {
			if (number[i] == false) inYoung[icnt++] = i;
		}
		permutation(0, 9, 9);
		printf("#%d %d %d\n", cnt++, win ,lose);
	}

	return 0;
}

//순열을 구현할 수 있는가 