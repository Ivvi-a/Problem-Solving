#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int MOD = 1000000007;
    int dp[1516][3]{}; // n자리수 중 나머지가 (0,5,10)인 경우
    fill(&dp[0][0], &dp[1515][3], 0);

    dp[1][1] = 1; // 1자리수 중 나머지가 5인 경우 : 5

    // 10, 100, 1000 ... -> 나머지 10
    // 5, 50, 500 ... -> 나머지 5
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD; // 5+10 / 10+5
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD; // 0+5 / 10+10
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD; // 0+10 / 5+5
    }

    cout << dp[N][0];
}