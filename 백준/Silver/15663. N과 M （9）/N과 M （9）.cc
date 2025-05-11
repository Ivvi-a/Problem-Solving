#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

int N, M;
bool visited[9];
vector<int> arr;
vector<int> seq;
set<string> seq_list;

void recur(int depth) {
	if (depth == M) {
		string s = "";
		for (int i = 0; i < M; i++) {
			s += to_string(seq[i]);
			if (i != M - 1) s += " ";
		}
		if (seq_list.find(s) != seq_list.end()) return;

		for (int i = 0; i < M; i++) {
			cout << seq[i];
			if (i != M - 1) cout << " ";
		}
		cout << "\n";
		seq_list.insert(s);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		seq.push_back(arr[i]);
		visited[i] = true;
		recur(depth + 1);
		seq.erase(seq.end() - 1);
		visited[i] = false;
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
	cin >> N >> M;
	init();
	recur(0);
	return 0;
}