#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> pii;

void posMv(deque<pii> & dq, int n) {
    while (n-- > 0 && !dq.empty()) {
        pii p = dq.front();
        dq.pop_front();
        dq.push_back(p);
    }
}

void negMv(deque<pii>& dq, int n) {
    while (n++ < 0 && !dq.empty()) {
        pii p = dq.back();
        dq.pop_back();
        dq.push_front(p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    deque<pii> dq;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        dq.push_back({i + 1, n});
    }

    while (!dq.empty()) {
        pii cur = dq.front();
        dq.pop_front();
        cout << cur.first << " ";

        int next = cur.second;
        if (next > 0) posMv(dq, next - 1);
        else negMv(dq, next);
    }
    return 0;
}