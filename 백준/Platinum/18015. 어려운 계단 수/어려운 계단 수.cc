#include<iostream>
#include<cstring>
#define MOD 1000000000
using namespace std;
int dp[2001][2001][2][2]; // dp[길이][마지막자릿수][0 존재여부][B-1 존재여부]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,B;
    cin >> N >> B;

    if (N < B) {
        cout << 0;
        return 0;
    }
    
    memset(dp, 0, sizeof dp);

    dp[1][B-1][0][1] = 1;
    for (int i = 1; i < B-1; i++) {
        dp[1][i][0][0] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int k = 0; k < B; k++) {
            if (k == 0) {
                for (int b = 0; b <= 1; b++) {
                    dp[i][k][1][b] = (dp[i][k][1][b] + dp[i - 1][k + 1][1][b] + dp[i - 1][k + 1][0][b]) % MOD;
                }
            }
            else if (k == B - 1) {
                for (int z = 0; z <= 1; z++) {
                    dp[i][k][z][1] = (dp[i][k][z][1] + dp[i - 1][k - 1][z][1] + dp[i - 1][k - 1][z][0]) % MOD;

                }
            }
            else {
                for (int b = 0; b <= 1; b++) {
                    for (int z = 0; z <= 1; z++) {
                        dp[i][k][z][b] = (dp[i][k][z][b] + dp[i - 1][k - 1][z][b] + dp[i - 1][k + 1][z][b]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < B; i++) {
        ans = (ans + dp[N][i][1][1]) % MOD;
    }

    cout << ans;

    return 0;
}