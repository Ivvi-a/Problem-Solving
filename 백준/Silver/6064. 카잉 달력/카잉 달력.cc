#include <iostream>
#include <numeric>
using namespace std;

int calc(int M, int N, int x, int y) {
    int res = -1;
    int lcm = (M * N) / gcd(M, N);
    
    while (x <= lcm && y <= lcm) {
        if (x == y) {
            res = x;
            break;
        }
        else if (x < y) {
            x += M;
        }
        else {
            y += N;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << calc(M, N, x, y) << "\n";
    }
    return 0;
}