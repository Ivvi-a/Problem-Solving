#include<iostream>
using namespace std;

int N, M;
long long pref[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	long long ans = 0;
	int before = 0;
	while (N-- > 0) {
		int a; cin >> a;
		int now = before + a;
		int rem = now % M;
		if (rem == 0) ans++;
		ans += pref[rem];
		pref[rem]++;
		before = rem;
	}
	cout << ans;
	return 0;
}