#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char campus[600][600] = {};
bool visited[600][600] = { false, };

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct Node {
    int y;
    int x;
};

int bfs(Node start, int Y, int X) {
    int cnt = 0;
    queue<Node> q;

    visited[start.y][start.x] = true;
    q.push(start);

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];

            if (nx < 0 || nx >= X || ny < 0 || ny >= Y || visited[ny][nx] || campus[ny][nx] == 'X') continue;
           
            q.push(Node{ ny, nx });
            visited[ny][nx] = true;

            if (campus[ny][nx] == 'P') {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Node start = {};

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int k = 0; k < M; k++) {
            campus[i][k] = str[k];
            if (campus[i][k] == 'I') {
                start = { i, k };
            }
        }
    }

    int ans = bfs(start, N, M);

    if (ans == 0) {
        cout << "TT";
    }
    else {
        cout << ans;
    }

    return 0;
}