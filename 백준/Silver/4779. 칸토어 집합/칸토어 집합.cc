#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void recur(int start, int end, int len, vector<bool> &v) {
    if (len < 1) return;
    recur(start, start + len - 1, len / 3, v);
    for (int i = start + len; i <= end - len; i++) {
        v[i] = false;
    }
    recur(end - len + 1, end, len / 3, v);
}

void print(vector<bool>& v) {
    for (bool b : v) {
        if (b) cout << "-";
        else cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    while (cin >> N) {
        int len = pow(3, N);
        vector<bool> v(len, true);
        recur(0, len - 1, len / 3, v);
        print(v);
    }
    return 0;
}