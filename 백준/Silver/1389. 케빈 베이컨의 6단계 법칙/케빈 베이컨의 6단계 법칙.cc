#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, answer;
int minRes = 25001;
int graph[101][101];
int sum[101];
bool visited[101];

void bfs(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next = 1; next <= N; next++) {
            if (!visited[next] && graph[now][next]) {
                sum[next] = sum[now] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        res += sum[i];
    }

    if (res < minRes) {
        minRes = res;
        answer = n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        fill(sum, sum+101, 0);
        fill(visited, visited+101, false);
        bfs(i);
    }

    cout << answer;
}