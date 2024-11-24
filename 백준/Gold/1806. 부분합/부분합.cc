#include <iostream>
#include <vector>
#define LIMIT 1000000000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,S;
    cin >> N >> S;

    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int ans = LIMIT;
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        sum += v[i];
        cnt++;
        while (sum-v[i-cnt+1] >= S) {
            sum -= v[i-cnt+1];
            cnt--;
        }
        if (sum >= S && cnt < ans) {
            ans = cnt;
        }
    }

    if (ans == LIMIT) cout << 0;
    else cout << ans;

    return 0;
}