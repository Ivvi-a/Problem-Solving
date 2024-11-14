#include <iostream>
#include <algorithm>
#define LIMIT 10000001;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 인접한 집끼리 색이 다를 것
    // 시작과 끝 집의 색이 다를 것
    
    int cost[1001][3]{};
    int dp[1001][3][3]{}; // N번째 집, 현재 지붕 색, 처음 지붕 색

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    fill(&dp[0][0][0], &dp[1][2][3], 10000001);

    for (int i = 0; i < 3; i++) {
        dp[1][i][i] = cost[1][i];
    }

    for (int i = 2; i <= N; i++) {
        for (int k = 0; k < 3; k++) {
            dp[i][0][k] = cost[i][0] + min(dp[i-1][1][k], dp[i-1][2][k]);
            dp[i][1][k] = cost[i][1] + min(dp[i-1][0][k], dp[i-1][2][k]);
            dp[i][2][k] = cost[i][2] + min(dp[i-1][0][k], dp[i-1][1][k]);
        }
    }

    int ans = LIMIT;

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            if (i == k) continue;
            ans = min(ans, dp[N][i][k]);
        }
    }

    cout << ans;
    
}