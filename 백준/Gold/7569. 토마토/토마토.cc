#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int tomato[101][101][101];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int X, Y, Z;

struct Node {
    int z, y, x;
};

queue<Node> q;

bool isRange(int x, int y, int z) {
    return x >= 0 && y >= 0 && z >= 0 && x < X && y < Y && z < Z && tomato[z][y][x] == 0;
}

int getResult() {
    int res = 0;
    for (int z = 0; z < Z; z++) {
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                int n = tomato[z][y][x];
                if (n == 0) {
                    return -1;
                }
                res = max(res, n);
            }
        }
    }
    return res - 1;
}

int bfs() {
    while (!q.empty()) {
        Node n = q.front();
        q.pop();

        for (int d = 0; d < 6; d++) {
            int nx = n.x + dx[d];
            int ny = n.y + dy[d];
            int nz = n.z + dz[d];

            if (isRange(nx, ny, nz)) {
                tomato[nz][ny][nx] = tomato[n.z][n.y][n.x] + 1;
                q.push(Node{ nz,ny,nx });
            }
        }
    }
    return getResult();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> X >> Y >> Z;

    bool isDone = true;
    for (int z = 0; z < Z; z++) {
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                cin >> tomato[z][y][x];
                if (tomato[z][y][x] == 0 && isDone) {
                    isDone = false;
                }
                else if (tomato[z][y][x] == 1) {
                    q.push(Node{ z,y,x });
                }
            }
        }
    }
    if (isDone) {
        cout << 0;
    }
    else {
        cout << bfs();
    }
    return 0;
}