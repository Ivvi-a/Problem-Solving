#include<iostream>
using namespace std;

int arr[2188][2188];

int cnt1, cnt2, cnt3 = 0;

void check(int size, int x, int y) {
	// cout << "size : " << size << " / x : " << x << " / y : " << y << "\n";

	int num = arr[y][x];

	if (size == 1) {
		if (num == -1) {
			cnt1++;
		}
		else if (num == 0) {
			cnt2++;
		}
		else {
			cnt3++;
		}
		return;
	}

	bool flag = true;

	// (x,y)부터 시작하는 가로세로 size 크기의 배열을 검사
	for (int i = x; i < x + size; i++) {
		for (int k = y; k < y + size; k++) {
			if (arr[k][i] != num) {
				flag = false;
				break;
			}
		}
	}

	if (flag) {
		// 재귀로 들어가지 않았을 때만 세어야 함
		if (num == -1) {
			cnt1++;
		}
		else if (num == 0) {
			cnt2++;
		}
		else {
			cnt3++;
		}
		return;
	}

	// 재귀
	int newSize = size / 3;

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			check(newSize, x + (newSize * i), y + (newSize * k));
		}
	}		
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cin >> arr[i][k];
		}
	}

	check(N, 0, 0);

	cout << cnt1 << "\n" << cnt2 << "\n" << cnt3;

	return 0;
}