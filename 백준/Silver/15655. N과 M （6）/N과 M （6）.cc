#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
bool visited[9];
vector<int> arr;
vector<int> seq;

void recur(int depth, int lastIdx) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << seq[i];
			if (i != M - 1) cout << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = lastIdx+1; i < N; i++) {
		if (visited[i]) continue;
		seq.push_back(arr[i]);
		visited[i] = true;
		recur(depth + 1, i);
		visited[i] = false;
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
	recur(0, -1);
	return 0;
} 