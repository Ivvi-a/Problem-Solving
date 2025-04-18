#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	vector<int> dp(N,1);
	int ans = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && dp[j] >= dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}