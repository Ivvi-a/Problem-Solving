#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int sudo[9][9];
vector<pii> zero;

void init() {
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            cin >> sudo[i][k];
            if (sudo[i][k] == 0) zero.push_back({ i, k });
        }
    }
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            cout << sudo[i][k];
            if (k != 8) cout << " ";
        }
        cout << "\n";
    }
}

bool sudoku(int depth) {
    if (depth == zero.size()) {
        print();
        return true;
    }

    int y = zero[depth].first;
    int x = zero[depth].second;
    bool isPossible[10];
    for (int i = 0; i < 10; i++) {
        isPossible[i] = true;
    }

    for (int i = 0; i < 9; i++) {
        isPossible[sudo[i][x]] = false;
        isPossible[sudo[y][i]] = false;
    }

    int nx = (x / 3) * 3;
    int ny = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            isPossible[sudo[ny + i][nx + k]] = false;
        }
    }

    // 재귀
    for (int i = 1; i <= 9; i++) {
        if (!isPossible[i]) continue;
        sudo[y][x] = i;
        if (sudoku(depth + 1)) return true;
        sudo[y][x] = 0;
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    if (zero.size() > 0) {
        bool res = sudoku(0);
    }
    return 0;
}