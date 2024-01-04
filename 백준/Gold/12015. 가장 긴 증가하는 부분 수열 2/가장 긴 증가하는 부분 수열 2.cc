#include <iostream>
#include <vector>
using namespace std;

int A[1000000], idx[1000000];
vector<int> v;

int binarySearch(int num) {
	int start = 0;
	int end = v.size() - 1;

	while (start < end) {
		int mid = (start + end) / 2;
		if (v[mid] < num) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	return end;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N; // 수열 A의 크기

	// 수열 입력받기
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// 첫번째 값 넣기
	v.push_back(A[0]);
	idx[0] = 0;

	// 두번째 값 ~ 끝까지
	for (int i = 1; i < N; i++) {
		int now = A[i];

		// 현재 값이 백터의 마지막 값보다 큰 경우
		if (v.back() < now) {
			v.push_back(now);
			idx[i] = v.size() - 1;
		}
		// 아닌 경우, 중간에 끼워넣어야 함(치환) -> 이분 탐색
		else {
			int nowIdx = binarySearch(now);
			idx[i] = nowIdx;
			v[nowIdx] = A[i];
		}
	}

	// LIS 길이 출력
	cout << v.size();

	return 0;
}