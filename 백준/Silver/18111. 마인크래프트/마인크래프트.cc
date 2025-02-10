#include <iostream>
#include <climits>
using namespace std;
typedef pair<int, int> pii;

const int INF = INT_MAX;
int Y, X, B;
int arr[500][500];

int removeBox(int n) {
    int removed = 0;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (arr[y][x] > n) {
                removed += arr[y][x] - n;
            }
        }
    }
    return removed;
}

int addBox(int n, int b) {
    int added = 0;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            int gap = n - arr[y][x];
            if (gap > 0) {
                added += gap;
                b -= gap;
                if (b < 0) return -1;
            }
        }
    }
    return added;
}

pii loopSet() {
    int minTime = INF;
    int maxHeight = 0;

    for (int n = 0; n <= 256; n++) {
        int removed = removeBox(n);
        if (removed * 2 > minTime) continue;
        int added = addBox(n, B + removed);
        int nTime = removed * 2 + added;
        if (added == -1) continue;
        else if(nTime <= minTime) {
            minTime = nTime;
            maxHeight = n;
        }
        
    }
    return make_pair(minTime, maxHeight);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> Y >> X >> B;

    for (int i = 0; i < Y; i++) {
        for (int k = 0; k < X; k++) {
            cin >> arr[i][k];
        }
    }
    pii ans = loopSet();
    cout << ans.first << " " << ans.second;
    return 0;
}