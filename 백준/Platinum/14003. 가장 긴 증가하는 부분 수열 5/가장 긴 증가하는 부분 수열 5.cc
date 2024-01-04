#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int *A, *idx;
vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N; // 수열 A의 크기
	A = new int[N];
	idx = new int[N];

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
			int start = 0;
			int end = v.size() - 1;

			while (start < end) {
				int mid = (start + end) / 2;
				if (v[mid] < now) {
					start = mid + 1;
				}
				else {
					end = mid;
				}
			}

			idx[i] = end;
			v[end] = A[i];
		}
	}

	// LIS 찾기 : 역순으로 찾은 후 뒤집기
	vector<int> LIS;
	int indexx = v.size() - 1;

	for (int i = N-1; i >= 0; i--) {
		if (indexx == idx[i]) {
			LIS.push_back(A[i]);
			indexx--;
			// 종료 조건
			if (indexx == -1) {
				break;
			}
		}
	}

	reverse(LIS.begin(), LIS.end());

	// LIS 길이 출력
	cout << v.size() << "\n";

	// LIS 출력
	for (int i = 0; i < LIS.size(); i++) {
		cout << LIS[i] << " ";
	}

	delete[] A;
	delete[] idx;

	return 0;
}
