#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
stack<int> s;
vector<int> v;

int main(){
	scanf("%d", &N);
	v.resize(N + 1, 0);
	for (int i = 0; i < N; i++) {
		int n; scanf("%d", &v[i]);
	}
	for (int i = 0; i <= N; i++) {
		while (!s.empty() && v[s.top()] > v[i]) {
			int idx = s.top(); s.pop();
			int w = i;
			if (!s.empty()) w = w - s.top() - 1;
			ans = max(ans, v[idx] * w);
		}
		s.push(i);
	}
	printf("%d", ans);
	return 0;
}

//stack을 이용한 풀이
//stack top에 있는 높이보다 작은 블록이 들어올 경우, 스택에 쌓여있던 블록을 빼내서 넓이를 계산
//stack top의 블록 높이보다 높은 블록은 스택에 넣음. 그러면 알아서 오름차순으로 정렬됨
//오름차순으로 입력되는 경우를 위해 마지막에 0값을 삽입