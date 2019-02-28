#include <stdio.h>
#include <vector>

#define LEFTNODE 0
#define RIGHTNODE 1

using namespace std;

vector<vector<int>> v;
vector<vector<int>> dist(10001);
int parent[10001];
int cnt, maxlevel;

void inorder(int node, int level) {
	if (v[node][LEFTNODE] != -1) inorder(v[node][LEFTNODE], level+1);
	dist[level].push_back(++cnt);
	if (maxlevel < level) maxlevel = level;
	if (v[node][RIGHTNODE] != -1) inorder(v[node][RIGHTNODE], level+1);
}

int main() {
	int N; scanf("%d", &N);
	v.resize(N + 1, vector<int>(2));
	for (int i = 1; i <= N; i++) {
		int n, leftnode, rightnode; scanf("%d", &n); scanf("%d %d", &leftnode, &rightnode);
		v[n][LEFTNODE] = leftnode; v[n][RIGHTNODE] = rightnode;
		if (leftnode != -1) parent[leftnode] = n;
		if (rightnode != -1) parent[rightnode] = n;
	}
	int root = 1;
	while (parent[root] != 0) {
		root = parent[root];
	}
	inorder(root, 1);
	int minlevel = 10001;
	int maxvalue = 0;
	for (int i = maxlevel; i > 0; i--) {
		int width = dist[i][dist[i].size() - 1] - dist[i][0] + 1;
		if (width >= maxvalue) {
			minlevel = i; maxvalue = width;
		}
	}
	printf("%d %d\n", minlevel, maxvalue);
	return 0;
}

//Tree를 잘 이해하고 있는지
//Inorder 순회를 구현 할 수 있는지 