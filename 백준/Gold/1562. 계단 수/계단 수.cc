#include <iostream>
#define MOD 1000000000
using namespace std;
typedef long long ll;

ll dp[101][10][1 << 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    if (N < 10) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < 10; i++) {
        dp[1][i][1 << i] = 1;
    }

    // i = 길이
    for (int i = 2; i <= N; i++) {
        // k = 마지막 숫자
        for (int k = 0; k < 10; k++) {
            // bit -> 포함된 숫자
            for (int bit = 0; bit < (1 << 10); bit++) {
                if (k == 0) {
                    dp[i][k][bit | 1 << k] += dp[i - 1][k + 1][bit] % MOD;
                }
                else if (k == 9) {
                    dp[i][k][bit | 1 << k] += dp[i - 1][k - 1][bit] % MOD;
                }
                else {
                    dp[i][k][bit | 1 << k] += (dp[i-1][k-1][bit] + dp[i-1][k+1][bit]) % MOD;
                }
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < 10; i++) {
        ans += dp[N][i][(1<<10)-1] % MOD;
        ans %= MOD;
    }

    cout << ans;

    return 0;
}