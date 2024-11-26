#include<iostream>
#define MOD 10007
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // dp[1] = 1
    // dp[2] = 3 = 2*dp[1] + 1
    // dp[3] = 5 = 2*dp[2] - 1
    // dp[4] = 3(1가지로만) + 3(ㅣ+ ㅁ) + 3(ㅣ+ ㅡ) + 2(ㅁ + ㅡ) = 11 = 2*dp[3] + 1
    // dp[5] = 1(1가지로만) + 7(ㅣ+ ㅁ) + 7(ㅣ+ ㅡ) + 6(ㅣ+ ㅡ + ㅁ) = 21 = 2*dp[4] - 1

    int n;
    cin >> n;

    int dp[1001];
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = (2 * dp[i - 1] + 1) % MOD;
        }
        else {
            dp[i] = (2 * dp[i - 1] - 1) % MOD;
        }
    }

    cout << dp[n];
    return 0;
}