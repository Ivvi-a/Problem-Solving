#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    int len = str.length();
    vector<vector<int>> v(len, vector<int>(26, 0));
    char c = str[0];
    v[0][c - 97] = 1;
    for (int i = 1; i < len; i++) {
        char c = str[i];
        for (int k = 0; k < 26; k++) {
            if (k == c - 97) {
                v[i][k] = v[i - 1][k] + 1;
            }
            else {
                v[i][k] = v[i - 1][k];
            }
        }
    }

    int q; cin >> q;
    while (q-- > 0) {
        char c; cin >> c;
        int s, e; cin >> s >> e;
        cout << v[e][c-97] - (s == 0 ? 0 : v[s-1][c-97]) << "\n";
    }

    return 0;
}