#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	ll N, B, C;
	cin >> N >> B >> C;

	vector<ll> v;
	ll cost = 0;

	if (B < C) {
		for (int i = 0; i < N; i++) {
			ll n;
			cin >> n;
			cost += B * n;
		}
	}
	else {
		// 라면사기 small
		for (int i = 0; i < N; i++) {
			ll n;
			cin >> n;
			v.push_back(n);
			while (v.size() == 3) {
				if (v[0] == 0) {
					v.erase(v.begin());
				}
				else {
					// 1개 삭제
					if (v[0] > v[1]) {
						ll tmp = v[0] - v[1];
						cost += B * tmp;
						v[0] -= tmp;
					}
					// 2개 삭제
					else if (v[0] < v[1] && v[1] > v[2]) {
						ll tmp = min(v[0], v[1] - v[2]);
						v[0] -= tmp;
						v[1] -= tmp;
						cost += tmp * (B + C);
					}
					else if (v[0] == v[1] && v[1] > v[2]) {
						ll tmp = v[1] - v[2];
						v[0] -= tmp;
						v[1] -= tmp;
						cost += tmp * (B + C);
					}
					// 3개 삭제
					else {
						ll tmp = max(1LL, min(v[0], min(v[1] - 1, v[2] - 1)));
						v[0] -= tmp;
						v[1] -= tmp;
						v[2] -= tmp;
						cost += tmp * (B + 2 * C);
					}
				}
			}

		}

		while (v.size() > 0) {
			if (v[0] == 0) {
				v.erase(v.begin());
			}
			else if (v.size() == 1) {
				cost += B * v[0];
				v.erase(v.begin());
			}
			else if (v[0] <= v[1]) {
				cost += (B + C) * v[0];
				v[1] -= v[0];
				v.erase(v.begin());
			}
			else {
				cost += (B + C) * v[1];
				v[0] -= v[1];
				v.erase(v.begin() + 1);
			}
		}
	}

	cout << cost;
}