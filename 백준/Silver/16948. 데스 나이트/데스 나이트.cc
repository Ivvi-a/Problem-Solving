#include<iostream>
#include <queue>
using namespace std;


bool visited[200][200]; // 방문 배열

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n; // 체스판의 크기

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2; // 시작점, 도착점

	// r1, c1 노드 넣기
	// 6방향 노드 넣고 방문 처리
	// r2, c2에 도착하면 cnt 출력 후 종료

	// BFS
	int answer = -1;
	queue<pair<int, int>> q;

	q.push(make_pair(r1, c1));
	visited[r1][c1] = true;

	while (!q.empty()) {
		answer++;
		// cout << "answer : " << answer << "\n";

		vector<pair<int, int>> temp;

		while (!q.empty()) {
			pair<int, int> p = q.front();
			// cout << "r : " << p.first  << " / c : " << p.second << "\n";;
			if (p.first == r2 && p.second == c2) {
				cout << answer;
				return 0;
			}

			visited[p.first][p.second] = true;
			q.pop();
			temp.push_back(p);
		}

		for (int i = 0; i < temp.size(); i++) {
			pair<int, int> node = temp[i];

			// node -> q // if !visited
			int r = node.first;
			int c = node.second;

			if (!visited[r][c - 2] && r < n && r >= 0 && c - 2 < n && c - 2 >=0) {
			 q.push(make_pair(r, c - 2));
			}
			if (!visited[r][c + 2] && r < n && r >= 0 && c + 2 < n && c + 2 >= 0) {
				q.push(make_pair(r, c + 2));
			}

			for (int i = -2; i <= 2; i += 4) {
				r = node.first + i;
				for (int k = -1; k <= 1; k += 2) {
					c = node.second + k;
					if (!visited[r][c] && r < n && c < n && r >= 0 && c >= 0) {
						q.push(make_pair(r, c));
						visited[r][c] = true;
					}
				}
			}

		}

	}

	cout << -1;

	return 0;
}