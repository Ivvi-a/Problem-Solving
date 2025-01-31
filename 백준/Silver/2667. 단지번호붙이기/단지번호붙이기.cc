#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int RANGE = 25;
char arr[RANGE][RANGE] = {};
bool visited[RANGE][RANGE] = { false, };

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct Node {
    int y;
    int x;
};

int bfs(Node start, int Y, int X) {
    int cnt = 1;
    queue<Node> q;

    visited[start.y][start.x] = true;
    q.push(start);

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];

            if (nx < 0 || nx >= X || ny < 0 || ny >= Y || visited[ny][nx] || arr[ny][nx] == '0') continue;
           
            q.push(Node{ ny, nx });
            visited[ny][nx] = true;
            cnt++;

        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    // 입력받기
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int k = 0; k < N; k++) {
            arr[i][k] = str[k];
        }
    }

    // 순회
    vector<int> v;
    int cnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (arr[y][x] == '1' && !visited[y][x]) {
                int res = bfs(Node{y,x}, N, N);
                v.push_back(res);
                cnt++;
            }
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}