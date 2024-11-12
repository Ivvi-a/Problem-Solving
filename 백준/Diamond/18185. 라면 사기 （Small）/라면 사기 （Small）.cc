#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v;
	int cost = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
		while (v.size() == 3) {
			if (v[0] == 0) {
				v.erase(v.begin());
			}
			else {
				// 1개 삭제
				if (v[0] > v[1]) {
					int tmp = v[0] - v[1];
					cost += 3 * tmp;
					v[0] -= tmp;
				}
				// 2개 삭제
				else if (v[0] < v[1] && v[1] > v[2]) {
					int tmp = min(v[0], v[1]-v[2]);
					v[0] -= tmp;
					v[1] -= tmp;
					cost += tmp * 5;
				}
				else if (v[0] == v[1] && v[1] > v[2]) {
					int tmp = v[1] - v[2];
					v[0] -= tmp;
					v[1] -= tmp;
					cost += tmp * 5;
				}
				// 3개 삭제
				else {
					int tmp = max(1,min(v[0], min(v[1] - 1, v[2] - 1)));
					v[0] -= tmp;
					v[1] -= tmp;
					v[2] -= tmp;
					cost += tmp * 7;
				}
			}
		}

	}

	while (v.size() > 0) {
		if (v[0] == 0) {
			v.erase(v.begin());
		}
		else if (v.size() == 1) {
			cost += 3 * v[0];
			v.erase(v.begin());
		}
		else if (v[0] <= v[1]) {
			cost += 5 * v[0];
			v[1] -= v[0];
			v.erase(v.begin());
		}
		else {
			cost += 5 * v[1];
			v[0] -= v[1];
			v.erase(v.begin() + 1);
		}
	}

	cout << cost;
}