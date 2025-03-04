#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    vector<int> v;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
            if (sum > n) break;
            v.push_back(i);
        }
    }
    if (sum == n) {
        cout << n << " = ";
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << " + ";
        }
        cout << v[v.size() - 1] << "\n";
    }
    else {
        cout << n << " is NOT perfect.\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;
        solve(n);
    }
    return 0;
}