#include <iostream>
#include <algorithm>
using namespace std;

int arr[8][8] = {
	{0,1,1,0,0,0,0,0}, // 0
	{1,0,1,1,0,0,0,0}, // 1
	{1,1,0,1,1,0,0,0}, // 2
	{0,1,1,0,1,1,0,0}, // 3
	{0,0,1,1,0,1,1,0}, // 4
	{0,0,0,1,1,0,0,1}, // 5
	{0,0,0,0,1,0,0,1}, // 6
	{0,0,0,0,0,1,1,0} // 7
};

int ans[8][8] = {
	{0,1,1,0,0,0,0,0}, // 0
	{1,0,1,1,0,0,0,0}, // 1
	{1,1,0,1,1,0,0,0}, // 2
	{0,1,1,0,1,1,0,0}, // 3
	{0,0,1,1,0,1,1,0}, // 4
	{0,0,0,1,1,0,0,1}, // 5
	{0,0,0,0,1,0,0,1}, // 6
	{0,0,0,0,0,1,1,0} // 7
};

int temp[8][8];

int dd = 1000000007;

void sqr(int r, int c);

int main()
{
	int D;
	cin >> D; // 제곱할 횟수
	
	while (D-- > 1) {
		// 제곱
		for (int r = 0; r < 8; r++) {
			for (int c = 0; c < 8; c++) {
				sqr(r,c);
			}
		}
		// 복사 temp -> ans
		for (int r = 0; r < 8; r++) {
			for (int c = 0; c < 8; c++) {
				ans[r][c] = temp[r][c];
			}
		}
	}

	// 출력
	cout << ans[0][0];

}

void sqr(int r, int c) {
	long long n = 0;

	for (int i = 0; i < 8; i++) {
		n += (static_cast<long long>(ans[r][i] % dd) * (arr[i][c]%dd)) % dd;
	}

	temp[r][c] = n % dd;

}