#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int K, V, E;
int color[20001];

void dfs(vector<vector<int>> &vertex, int nowVertex, int preVertex) {
	if (preVertex == 0) color[nowVertex] = 1;
	else {
		if (color[preVertex] == 1) color[nowVertex] = 2;
		else color[nowVertex] = 1;
	}

	int len = vertex[nowVertex].size();

	for (int i = 0; i < len; i++) {
		if (color[vertex[nowVertex][i]] != 0) continue;
		else dfs(vertex, vertex[nowVertex][i], nowVertex);
	}
}

bool isPossible(vector<vector<int>> &vertex) {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < vertex[i].size(); j++) {
			if (color[i] == color[vertex[i][j]]) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d", &V, &E);
		int v1, v2;
		memset(color, 0, sizeof(color));
		vector<vector<int>> Vertex(V + 1);
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &v1, &v2);
			Vertex[v1].push_back(v2);
			Vertex[v2].push_back(v1);
		}
		for (int i = 1; i <= V; i++) if (!color[i]) dfs(Vertex, i, 0);

		if (isPossible(Vertex)) printf("YES\n");
		else printf("NO\n");

	}
	return 0;
}

//DFS 