#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> paper;
int N, blue, white = 0;

bool isAllSame(int startX, int startY, int length)
{
	int color = paper[startY][startX];
	for (int y = startY; y < startY + length; y++) {
		for (int x = startX; x < startX + length; x++) {
			if (paper[y][x] != color) {
				return false;
			}
		}
	}
	return true;
}

void solve(int startX, int startY, int length) {
	// 1. 모든 색이 같은지 확인한다.
	if (length == 1 || isAllSame(startX, startY, length) == true) {
		// 2-1. 맞다면, 해당 색깔 카운트하고 멈춤
		if (paper[startY][startX] == 0) {
			white++;
		}
		else {
			blue++;
		}
	}
	else {
		// 2-2. 아니라면, 4등분해서 재귀한다.
		int half = length / 2;
		solve(startX, startY, half);
		solve(startX + half, startY, half);
		solve(startX, startY + half, half);
		solve(startX + half, startY + half, half);
	}
}

void init() {
	cin >> N;
	paper = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> paper[y][x];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	solve(0, 0, N);
	cout << white << "\n" << blue;
	return 0;
}