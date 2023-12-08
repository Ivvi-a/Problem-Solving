#include <iostream>
#include <algorithm>
using namespace std;

int arr[9][9];

void fill(int y, int x);
void print();

int main()
{
    // 스도쿠 입력받기
    for (int i = 0; i < 9; i++) {
        int n;
        cin >> n;
        for (int k = 8; k >= 0; k--) {
            arr[i][k] = n % 10;
            n /= 10;
        }
    }

    // 스도쿠 채우기
    fill(0, 0);

}

void fill(int y, int x) {
    // 마지막 칸을 채우고 들어온 경우 (8,8) -> (9,0)
    if (y > 8) {
        print();
        exit(0);
    }

    // 다음 칸 index
    int nx = x + 1;
    int ny = y;
    if (nx == 9) {
        ny += 1;
        nx = 0;
    }
    
    // 채워진 칸인 경우
    if (arr[y][x] > 0) {
        fill(ny, nx);
        return;
    }

    // 빈 칸인 경우
    bool num[10] = { false };

    // 가로
    for (int i = 0; i < 9; i++) {
        int n = arr[y][i];
        if (n > 0) {
            num[n] = true;
        }
    }
    // 세로
    for (int i = 0; i < 9; i++) {
        int n = arr[i][x];
        if (n > 0) {
            num[n] = true;
        }
    }
    // 네모
    int sy = (y / 3) * 3;
    int sx = (x / 3) * 3;

    // 0 ~ 2 -> 0 (0)
    // 3 ~ 5 -> 3 (1)
    // 6 ~ 8 -> 6 (2)
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            int n = arr[sy + i][sx + k];
            if (n > 0) {
                num[n] = true;
            }
        }
    }
    
    // 없는 수 찾아서 재귀
    for (int i = 1; i <= 9; i++) {
        if (!num[i]) {
            // 빈칸을 i로 채우기
            arr[y][x] = i;
            fill(ny, nx);
            arr[y][x] = 0;
        }
    }
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            cout << arr[i][k];
        }
        cout << "\n";
    }
}