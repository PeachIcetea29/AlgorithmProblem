#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int arr[20][20];
int N;
int ans = 2e9;
int team1[10];
int team2[10];

int abs(int n) {
	return n > 0 ? n : -n;
}

int getScore(int team[] ) {
	int sum = 0;
	int len = N / 2;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			sum += arr[team[i]][team[j]];
		}
	}
	return sum;
}

void dfs(int start, int count) {
	if (count == N / 2){ 
		int team1_score = getScore(team1);
		int tcnt = 0;
		int teamLen = N / 2;
		for (int i = 0; i < N; i++) {
			bool isTeam = false;
			for (int j = 0; j < teamLen; j++) {
				if (i == team1[j]) {
					isTeam = true; break;
				}
			}
			if (!isTeam) team2[tcnt++] = i;
		}
		int team2_score = getScore(team2);
		int temp = abs(team1_score - team2_score);
		ans = min(ans, temp);
		return;
	}

	for (int i = start; i < N; i++) {
		team1[count] = i;
		dfs(i + 1, count + 1);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}

//Brute force