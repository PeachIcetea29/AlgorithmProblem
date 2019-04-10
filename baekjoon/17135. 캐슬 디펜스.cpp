#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, D, ans;
int arr[16][15];
int position[3];
vector<vector<pair<int,bool>>> enemy(15);

int _abs(int n) {
	return n > 0 ? n : -n;
}

int defense() {
	vector<vector<pair<int, bool>>> v(enemy);
	int cnt = 0;
	for (int r = N; r > 0; r--) { // #2

		vector<pair<int, int>> kill;

		for (int i = 0; i < 3; i++) {
			int dmin = 2e9;
			int cmin = 2e9;
			pair<int, int> temp;
			bool isFind = false;

			for (int j = r-1; j >= 0; j--) {
				if (r - j > D) break;

				for (int k = 0; k < v[j].size(); k++) {
					int d = r - j + _abs(position[i] - v[j][k].first);
					if (v[j][k].second == true &&  d <= D && (dmin > d || (dmin == d && v[j][k].first < cmin) ) ) {
						dmin = d; cmin = v[j][k].first;
						temp = { j, k };
						isFind = true;
					}
				}
			}
			if(isFind) kill.push_back(temp);

		}
		for (int i = 0; i < kill.size(); i++) {
			int j = kill[i].first; int k = kill[i].second;
			if (v[j][k].second == true) {
				v[j][k].second = false; cnt++;
			}
		}
	}
	return cnt;
}

void selectPosition(int count, int start) {
	if (count == 3) {
		ans = max(ans, defense()); // #3
		return;
	}
	for (int i = count; i < M; i++) {
		position[count] = i;
		selectPosition(count + 1, i+1);
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 1) enemy[i].push_back({ j, true }); // #1
		}
	}
	selectPosition(0, 0);
	printf("%d", ans);
	return 0;
}

//브루트 포스
//적의 위치와 생존 유무를 따로 저장 -- #1
//성이 있는 row를 기점으로 한칸씩 줄여가며 일일히 체크 -- #2
//모든 경우를 다 따져서 얻을 수 있는 최대값 출력 -- #3

//근데 배열로 탐색하지 말고, 그냥 적군만 따져서 탐색하는 것이 더 좋은 방법
//list를 사용해서 사거리를 체크하고, 삭제하는 방식