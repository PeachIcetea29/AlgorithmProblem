#include <iostream>
#include <string>

using namespace std;

int k;
char arr[9];
int number[10];
string maxi = "0";
string mini = "9999999999";

long long stringToLongLong(string s) {
	int len = s.length();
	long long n = 0;
	for (int i = 0; i < len; i++) n = (n * 10) + s[i] - '0';
	return n;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool isPossible(int i) {
	if (i == -1) return true;
	
	if (arr[i] == '<' && number[i] < number[i + 1]) return true;
	else if (arr[i] == '>' && number[i] > number[i + 1]) return true;
	else return false;
}

void permutation(int depth, int n, int r) {
	if (depth == r) {
		string s;
		for (int i = 0; i < k+1; i++) s += to_string(number[i]);
		if (stringToLongLong(s) > stringToLongLong(maxi)) maxi = s;
		if (stringToLongLong(s) < stringToLongLong(mini)) mini = s;
	}

	for (int i = depth; i < n; i++) {
		swap(&number[i], &number[depth]);
		if(isPossible(depth-1)) permutation(depth + 1, n, r);
		swap(&number[i], &number[depth]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> k;
	for (int i = 0; i < k; i++) cin >> arr[i];
	for (int i = 0; i < 10; i++) number[i] = i;
	permutation(0, 10, k+1);
	cout << maxi << "\n" << mini;
	return 0;
}

//순열 구현
//백트래킹 
//STL algorithm 라이브러리의 next_permutation(begin, end), prev_permutation(begin, end)도 사용 가능