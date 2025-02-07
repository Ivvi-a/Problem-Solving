#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int loc, v;
};

int N, M;
int arr[101] = {0,};
bool visited[101];

int bfs() {
    queue<Node> q;
    q.push(Node{ 1,0 });
    visited[1] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next;
            if (arr[node.loc + i] > 0) {
                next = arr[node.loc + i];
            }
            else {
                next = node.loc + i;
            }
            
            if (next == 100) return node.v + 1;
            if (visited[next]) continue;

            q.push(Node{ next, node.v + 1 });
            visited[next] = true;
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int idx;
        cin >> idx;
        cin >> arr[idx];
    }

    for (int i = 0; i < M; i++) {
        int idx;
        cin >> idx;
        cin >> arr[idx];
    }

    cout << bfs();
 
    return 0;
}