#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> seq;

void recur(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << seq[i];
			if (i != M - 1) cout << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		seq.push_back(arr[i]);
		recur(depth + 1);
		seq.erase(seq.end() - 1);
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N; cin >> M;
	init();
	recur(0);
	return 0;
} 