#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, string> pis;

int D(int n) {
    return (2 * n) % 10000;
}

int S(int n) {
    if (n == 0) return 9999;
    return n - 1;
}

int L(int n) {
    int d1 = n / 1000;
    n -= d1 * 1000;
    n *= 10;
    n += d1;
    return n;
}

int R(int n) {
    int d4 = n - ((n / 10) * 10);
    n /= 10;
    n += d4 * 1000;
    return n;
}

string BFS(int num, int goal) {
    queue<pis> q; // 현재 수, 사용한 명령어들
    bool visited[10000] = { false, };
    q.push({ num, "" });
    visited[num] = true;

    while (!q.empty()) {
        pis now = q.front();
        q.pop();
        int nowNum = now.first;
        string nowCmd = now.second;
        if (nowNum == goal) return nowCmd;

        int nextNum[4] = { D(nowNum), S(nowNum), L(nowNum), R(nowNum)};
        char cmd[4] = { 'D', 'S', 'L', 'R' };

        for (int i = 0; i < 4; i++) {
            if (visited[nextNum[i]]) continue;
            visited[nextNum[i]] = true;
            q.push({ nextNum[i], nowCmd + cmd[i] });
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int A, B; cin >> A >> B;
        cout << BFS(A, B) << "\n";
    }
    return 0;
}