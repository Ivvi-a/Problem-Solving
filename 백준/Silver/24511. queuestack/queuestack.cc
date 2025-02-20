#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (n == 0) v[i] = 1;
        else if (n == 1) v[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (v[i] == 0) continue;
        else v[i] = n;
    }

    deque<int> dq;
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int n; cin >> n;
        dq.push_back(n);
    }

    for (int i = 0; i < N; i++) {
        if (v[i] == 0) continue;
        else {
            dq.push_front(v[i]);
            dq.pop_back();
        }
    }

    for (int i : dq) {
        cout << i << " ";
    }
    
    return 0;
}