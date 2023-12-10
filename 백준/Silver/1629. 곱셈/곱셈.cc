#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

int mod;

ll power(ll num, ll n) {
	if (n == 0) {
		return 1;
	}

	ll x = power(num, n / 2) % mod;

	if (n & 1) {
		return ((x * x )% mod * num) % mod;
	}
	else {
		return (x * x) % mod;;
	}

}

int main()
{
	ll num, n;
	cin >> num >> n >> mod;

	ll ans = power(num, n) % mod;

	cout << ans;
}