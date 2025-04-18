#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int makeTree(int node, int start, int end);
void updateTree(int node, int start, int end, int target);
int getSum(int node, int start, int end, int left, int right);

int N;
vector<pair<int,int>> arr;
vector<int> tree;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	// 세그먼트 트리 초기화
	tree.resize(4 * N);
	makeTree(1, 1, N);

	// 수 입력 받기
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr.push_back({ n,i+1 });
	}
	sort(arr.begin(), arr.end());

	// 바뀌는 횟수 구하기 : 해당 수의 위치(인덱스) 찾기 -> 인덱스 기준으로 구간 합 구하기 -> 트리 갱신
	for (int i = 0; i < (N+1)/2; i++) {
		// 홀수 번째 -> 1 ~ n-1
		int idx = arr[i].second;
		cout << getSum(1, 1, N, 1, idx - 1) << "\n";

		updateTree(1, 1, N, idx); // 트리 값 갱신 (1 -> 0)

		// N이 홀수일 때 종료 조건
		if (1 + i == N - i) {
			//cout << "end : " << 1 + i << " / " << N - i << "\n";
			break;
		}

		// 짝수 번째 -> n+1 ~ N
		idx = arr[N - 1 - i].second;
		cout << getSum(1, 1, N, idx + 1, N) << "\n";
		
		updateTree(1, 1, N, idx); // 트리 값 갱신 (1 -> 0)

	}

	return 0;
}

// 세그먼트 트리 만들기
int makeTree(int node, int start, int end) {
	if (start == end) {
		return tree[node] = 1;
	}

	int mid = (start + end) / 2;

	return tree[node] = makeTree(node * 2, start, mid) + makeTree(node * 2 + 1, mid + 1, end);
}

// 트리 값 갱신
void updateTree(int node, int start, int end, int target) {
	if (target < start || end < target) {
		return;
	}

	tree[node] -= 1;

	if (start != end) {
		int mid = (start + end) / 2;
		updateTree(node * 2, start, mid, target);
		updateTree(node * 2 + 1, mid + 1, end, target);
	}
}

// 구간 합 구하기
int getSum(int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return getSum(node * 2, start, mid, left, right) + getSum(node * 2 + 1, mid + 1, end, left, right);
}