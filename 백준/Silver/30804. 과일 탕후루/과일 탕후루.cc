#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    // 변하는 지점을 체크한다
    int ptr = 0;
    int cnt = 0;
    int ans = 1;
    set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(v[i]);
        if (s.size() > 2) {
            ans = max(ans, cnt);
            s.clear();
            i = ptr-1;
            cnt = 0;
        }
        else {
            cnt++;
        }
        if (i > 0 && v[i] != v[i - 1]) {
            ptr = i;
        }
    }
    ans = max(ans, cnt);

    cout << ans;
    return 0;
}