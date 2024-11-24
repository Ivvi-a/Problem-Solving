#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int dp[101][10]{};

    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int k = 1; k <= 8; k++) {
            dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k + 1])%MOD;
        }
    }

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        ans += dp[N][i] % MOD;
        ans %= MOD;
    }

    cout << ans;

    return 0;
}