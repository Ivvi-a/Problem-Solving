#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}

	int ans = min(a[0], min(a[1], min(a[2]-a[0], a[3]-a[1])));
	cout << ans;

	return 0;
}