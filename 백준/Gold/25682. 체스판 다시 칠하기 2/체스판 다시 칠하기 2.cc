#include <iostream>
#include <algorithm>
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
		for (int k = 0; k < M; k++) {
			if (k != 0) idx = (idx + 1) % 2;
			pref[i][k][0] = prefVal(i - 1, k, 0) + prefVal(i, k - 1, 0) - prefVal(i - 1, k - 1, 0);
			pref[i][k][1] = prefVal(i - 1, k, 1) + prefVal(i, k - 1, 1) - prefVal(i - 1, k - 1, 1);
			if (org[i][k] != bw[idx]) pref[i][k][0]++;
			else pref[i][k][1]++;
		}
	}

	// 3. 최소 수 구하기
	int ans = 2000*2000 + 1;
	for (int i = K-1; i < N; i++) {
		for (int k = K-1; k < M; k++) {
			int pref1 = pref[i][k][0] - prefVal(i, k - K, 0) - prefVal(i - K, k, 0) + prefVal(i - K, k - K, 0);
			int pref2 = pref[i][k][1] - prefVal(i, k - K, 1) - prefVal(i - K, k, 1) + prefVal(i - K, k - K, 1);
			ans = min(ans, min(pref1, pref2));
		}
	}
	cout << ans;
	return 0;
}