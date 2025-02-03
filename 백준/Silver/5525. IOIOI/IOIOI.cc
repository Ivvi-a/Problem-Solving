#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M; string str;
    cin >> N >> M >> str;
   
    int ans = 0;
    int cnt = 0;
    char bf = 'X';
    for (int i = 0; i < M; i++) {
        char c = str[i];
        if (c == 'I') {
            if (bf == 'O') {
                cnt++;
            }
            else {
                if (cnt >= 2 * N + 1) {
                    ans += ((cnt - 1) / 2) - N + 1;
                }
                cnt = 1;
            }
            bf = 'I';
        }
        else if (c == 'O') {
            if (bf == 'I') {
                cnt++;
                bf = 'O';
            }
            else {
                if (cnt >= 2 * N + 1) {
                    ans += ((cnt - 1) / 2) - N + 1;
                }
                cnt = 0;
                bf = 'X';
            }
        }
    }
    if (cnt >= 2 * N + 1) {
        ans += ((cnt - 1) / 2) - N + 1;
    }
    
    cout << ans;
    return 0;
}