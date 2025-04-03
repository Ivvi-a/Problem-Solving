#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	vector<int> dist(N-1);
	vector<int> cost(N);
	int nowIdx = 0;
	ll answer = 0;

	for (int i = 0; i < N-1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}

	while (true) {
		int nowCost = cost[nowIdx];
		int cnt = 1;
		// 1. 현재 도시 - 다음 도시들 cost 비교 (마지막 도시는 보지 않는다)
		for (int i = nowIdx+1; i < N-1; i++) {
			if (nowCost > cost[i]) break;
			cnt++;
		}
		// 2. 비용 더하고 현재 위치 갱신
		for (int i = nowIdx; i < nowIdx + cnt; i++) {
			answer += (ll) dist[i] * nowCost;
		}
		nowIdx += cnt;
		// 3. 현재 위치가 마지막 지점이면 끝
		if (nowIdx == N-1) break;
	}

	cout << answer;

	return 0;
}