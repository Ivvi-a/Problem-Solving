#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int M; cin >> M;
	int K; cin >> K;
	int X; cin >> X;

	// 그래프 입력
	vector<vector<int>> graph (N+1);
	for (int i = 0; i < M; i++) {
		int s, e; cin >> s >> e;
		graph[s].push_back(e);
	}

	// BFS
	queue<int> q;
	q.push(X);
	vector<bool> visited(N + 1, false);
	visited[X] = true;
	int cnt = 0;

	while (cnt < K) {
		vector<int> nowNodes;
		while (!q.empty()) {
			nowNodes.push_back(q.front());
			q.pop();
		}
		for (int i = 0; i < nowNodes.size(); i++) {
			int nowNode = nowNodes[i];
			for (int j = 0; j < graph[nowNode].size(); j++) {
				int nextNode = graph[nowNode][j];
				if (visited[nextNode]) continue;
				q.push(nextNode);
				visited[nextNode] = true;
			}
		}
		cnt++;
	}

	// 정답 출력
	if (q.empty()) cout << -1;
	else {
		vector<int> ans;
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}

	return 0;
}