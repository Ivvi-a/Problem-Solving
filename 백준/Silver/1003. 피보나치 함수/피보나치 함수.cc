#include <iostream>
using namespace std;

int arr[41][2];

int func0(int n) {
    if (arr[n][0] != -1) {
        return arr[n][0];
    }

    arr[n - 1][0] = func0(n - 1);
    arr[n - 2][0] = func0(n - 2);

    return arr[n - 1][0] + arr[n - 2][0];
}

int func1(int n) {
    if (arr[n][1] != -1) {
        return arr[n][1];
    }

    arr[n - 1][1] = func1(n - 1);
    arr[n - 2][1] = func1(n - 2);

    return arr[n - 1][1] + arr[n - 2][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(&arr[0][0], 41 * 2, -1);
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        cout << func0(N) << " " << func1(N) << "\n";
    }
    
}