#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[50001];

int calcA(int n) {
    return pow((int)sqrt(n), 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        int a = i - calcA(i);
        if (a == 0) {
            dp[i] = 1;
        }
        else {
            dp[i] = 4;
            for (int k = 1; k*k <= i; k++) {
                dp[i] = min(dp[i - k*k] + 1, dp[i]);
            }
        }
    }

    cout << dp[N];
    return 0;
}