#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans = 0;
bool graph[1001][1001];
bool visited[1001];

void BFS(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && graph[now][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            ans++;
            BFS(i);
        }
    }

    cout << ans;

    return 0;
}