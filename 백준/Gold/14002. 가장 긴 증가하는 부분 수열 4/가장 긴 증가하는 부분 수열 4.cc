#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	vector<int> dp(N, 1);
	int maxLen = 1;
	int idx = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
			if (dp[i] > maxLen) {
				maxLen = dp[i];
				idx = i;
			}
		}
	}
	cout << maxLen << "\n";

	// 역추적
	stack<int> s;
	s.push(v[idx]);
	for (int i = idx-1; i >= 0; i--) {
		if (dp[i] == maxLen-1 && s.top() > v[i]) {
			s.push(v[i]);
			maxLen--;
		}
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}