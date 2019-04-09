#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<long long> ans;
vector<long long> v;
vector<vector<int>> node;

bool dfs(int idx, int nth) {
	if (nth == N) {
		ans.push_back(v[idx]);
		return true;
	} 
	if (node[idx].size() == 0) return false;

	ans.push_back(v[idx]);
	dfs(node[idx][0], nth + 1);
}

int main() {
	scanf("%d", &N);
	v.resize(N); node.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &v[i]);
	}
	for (int i = 0; i < N; i++) {
		long long Di3 = v[i] / 3;
		long long Ml2 = v[i] * 2;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (Ml2 == v[j]) node[i].push_back(j);
			if (Di3 * 3 == v[i] && Di3 == v[j]) node[i].push_back(j);
		}
	}
	for (int i = 0; i < N; i++) {
		ans.clear();
		if (dfs(i, 1)) {
			for (int i = 0; i < N; i++) {
				printf("%lld ", ans[i]);
			}
			break;
		}
	}
	return 0;
}

//DFS, topological sorting?
//다음에 올 숫자를 저장.
//10^18이기 때문에 long long