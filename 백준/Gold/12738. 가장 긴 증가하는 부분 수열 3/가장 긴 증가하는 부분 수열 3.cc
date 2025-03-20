#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	vector<int> v;
	while (N-->0) {
		int n; cin >> n;
		if (v.empty() || v.back() < n) {
			v.push_back(n);
		}
		else {
			auto pos = lower_bound(v.begin(), v.end(), n);
			*pos = n;
		}
	}
	cout << v.size();
	return 0;
}