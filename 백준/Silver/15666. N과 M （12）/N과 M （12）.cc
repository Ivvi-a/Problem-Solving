#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

int N, M;
vector<int> arr; // 입력받은 배열
vector<int> seq; // 수열
set<string> seq_list; // 중복 체크용

void print() {
	string s = "";
	for (int i = 0; i < M; i++) {
		s += to_string(seq[i]);
		if (i != M - 1) s += " ";
	}
	if (seq_list.find(s) != seq_list.end()) return; // 중복인 경우
	seq_list.insert(s);
	cout << s << "\n";
}

void recur(int depth, int lastIdx) {
	if (depth == M) {
		print();
		return;
	}

	for (int i = lastIdx; i < N; i++) {
		seq.push_back(arr[i]);
		recur(depth + 1, i);
		seq.erase(seq.end() - 1);
	}
}

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	recur(0, 0);
	return 0;
}