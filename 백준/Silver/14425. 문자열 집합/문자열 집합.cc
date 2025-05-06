#include<iostream>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N; cin >> M;
	set<string> s;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		s.insert(str);
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		string str; cin >> str;
		if (s.find(str) != s.end()) {
			ans++;
		}
	}

	cout << ans;
	return 0;
} 