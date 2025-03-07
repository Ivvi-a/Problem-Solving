#include <bits/stdc++.h>
using namespace std;

int N, M, K;
char org[2001][2001];
int pref[2001][2001][2];
char bw[] = { 'B', 'W' };

int prefVal(int y, int x, int z) {
	if (y < 0 || x < 0) return 0;
	else return pref[y][x][z];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	// 1. 체스판 저장
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int k = 0; k < M; k++) {
			org[i][k] = s[k];
		}
	}

	// 2. 누적합
	int idx = 0; 
	for (int i = 0; i < N; i++) {
		if(M%2 != 0) idx = (idx + 1) % 2;
		for (int j = 0; j < M; j++) {
			if (j != 0) idx = (idx + 1) % 2;
			pref[i][j][0] = prefVal(i - 1, j, 0) + prefVal(i, j - 1, 0) - prefVal(i - 1, j - 1, 0);
			pref[i][j][1] = prefVal(i - 1, j, 1) + prefVal(i, j - 1, 1) - prefVal(i - 1, j - 1, 1);
			if (org[i][j] != bw[idx]) pref[i][j][0]++;
			else pref[i][j][1]++;
		}
	}

	// 3. 최소 수 구하기
	int ans = 2000*2000 + 1;
	for (int i = K-1; i < N; i++) {
		for (int j = K-1; j < M; j++) {
			int pref1 = pref[i][j][0] - prefVal(i, j - K, 0) - prefVal(i - K, j, 0) + prefVal(i - K, j - K, 0);
			int pref2 = pref[i][j][1] - prefVal(i, j - K, 1) - prefVal(i - K, j, 1) + prefVal(i - K, j - K, 1);
			ans = min(ans, min(pref1, pref2));
		}
	}
	cout << ans;
	return 0;
}