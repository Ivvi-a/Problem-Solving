#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> poweredPrime;

void sqrtList(ll N) {
    int range = static_cast<int>(ceil(sqrt(4.0 * N)));
    vector<bool> isPrime(range + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= range; i++) {
        if (isPrime[i]) {
            for (int k = 2 * i; k <= range; k+=i) {
                if (isPrime[k]) isPrime[k] = false;
            }
            poweredPrime.push_back(1LL* i * i);
        }
    }
}

ll nonSquareFree(ll num, int idx, ll mul, int cnt) {
    ll res = 0;

    for (int i = 0; i < idx; i++) {
        ll temp = poweredPrime[i] * mul;
        if (temp > num) break;

        if (cnt % 2 == 1) {
            res += num / temp;
        }
        else {
            res -= num / temp;
        }

        res += nonSquareFree(num, i, temp, cnt + 1);
    }

    return res;
}


ll binarySearch(ll start, ll end) {
    ll ans = 0;
    ll N = start;

    while (start <= end) {
        ll mid = start + (end - start) / 2;
        ll cnt = nonSquareFree(mid, poweredPrime.size(), 1, 1);

        if (cnt >= N) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    sqrtList(N);
    cout << binarySearch(N, 4.0*N);


    return 0;
}