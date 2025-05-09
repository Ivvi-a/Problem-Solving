#include<iostream>
#include<vector>
using namespace std;

int N, M;
bool visited[9];
vector<int> v;

void recur(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i];
			if (i != M - 1) cout << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		recur(depth + 1);
		v.erase(v.end() - 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N; cin >> M;
	recur(0);
	return 0;
} 