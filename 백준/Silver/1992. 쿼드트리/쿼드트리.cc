#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool isAllSame(vector<vector<int>>& v, int x, int y, int len) {
	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if(v[y][x] != v[i][j]) {
				return false;
			}
		}
	}
	return true;
}

string solve(string s, vector<vector<int>>& v, int x, int y, int len) {
	// 1. 전체 색깔이 같은지 확인한다
	if (isAllSame(v, x, y, len) == true) {
		// 2-1. 같다면 string에 숫자를 저장
		return to_string(v[y][x]);
	}
	else {
		// 2-2. 다르다면 4등분해서 재귀
		int half = len / 2;
		string ss = "(";
		ss += solve(s, v, x, y, half);
		ss += solve(s, v, x + half, y, half);
		ss += solve(s, v, x, y + half, half);
		ss += solve(s, v, x+ half, y+ half, half);
		ss += ")";
		return ss;
	}
}

vector<vector<int>> init() {
	int N;
	cin >> N;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			v[i][j] = s[j] - '0';
		}
	}
	return v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> v = init();
	string answer = solve("", v, 0, 0, v.size());
	cout << answer;
	return 0;
}