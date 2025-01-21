#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;

ll calcSum(ll h) {
    ll sum = 0;
    for (int i = 0; i < v.size(); i++) {
        ll len = v[i] - h;
        if (len <= 0) continue;
        sum += len;
    }
    return sum;
}

ll binarySearch(ll a, ll b, ll target) {
    ll start = a;
    ll end = b;
    ll ans = -1;

    while (start < end) {
        ll mid = (end - start) / 2 + start;
        ll res = calcSum(mid);
        if (res < target) {
            end = mid;
        }
        else if(res > target){
            if (mid > ans) {
                ans = mid;
                start = mid;
            }
            else {
                break;
            }
        }
        else {
            ans = mid;
            break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        ll n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    ll ans = binarySearch(0, v[v.size() - 1], M);

    cout << ans;

    return 0;
}