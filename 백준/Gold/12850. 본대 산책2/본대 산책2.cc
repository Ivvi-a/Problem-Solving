#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix arr = {
	{0,1,1,0,0,0,0,0}, // 0
	{1,0,1,1,0,0,0,0}, // 1
	{1,1,0,1,1,0,0,0}, // 2
	{0,1,1,0,1,1,0,0}, // 3
	{0,0,1,1,0,1,1,0}, // 4
	{0,0,0,1,1,0,0,1}, // 5
	{0,0,0,0,1,0,0,1}, // 6
	{0,0,0,0,0,1,1,0} // 7
};

matrix ans = {
	{1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,1}
};

const int mod = 1000000007;

matrix operator * (matrix& a, matrix& b) {
	matrix temp(8, vector<long long>(8));

	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			for (int i = 0; i < 8; i++) {
				temp[r][c] += (a[r][i] * b[i][c]);
			}
			temp[r][c] %= mod;
		}
	}

	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int D;
	cin >> D; // 제곱할 횟수

	while (D > 0) {
		if (D & 1) {
			ans = ans * arr;
		}

		arr = arr * arr;
		D = D >> 1;

	}

	// 출력
	cout << ans[0][0];

	return 0;
}