#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

bool isPrime[1000001];
int indexArr[1000001]; // key 수 value 인덱스
int score[100001]; // key 인덱스 value 점수
void getPrime();
void calcScore(int n, int idx);

// 1부터 제곱근까지 나눠본다 (key 수 - value 인덱스)
// 수가 존재하면 자신-1, 수+1 (key 인덱스 - value 점수)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    getPrime();
    memset(indexArr,-1, sizeof(indexArr));

    vector<int> cards;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        indexArr[n] = i;
        cards.push_back(n);
    }

    // 점수 계산
    for (int i = 0; i < N; i++) {
        int n = cards[i];
        if (indexArr[1] != -1) {
            score[i]--;
            score[indexArr[1]]++;
        }
        if (isPrime[n]) {
            continue;
        }
        else {
            calcScore(n, i);
        }
    }

    // 출력
    for (int i = 0; i < N; i++) {
        cout << score[i] << " ";
    }

    return 0;
}


void getPrime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < 1000001; i++) {
        if (isPrime[i]) {
            for (int k = 2 * i; k < 1000001; k += i) {
                isPrime[k] = false;
            }
        }
    }
}

void calcScore(int n, int idx) {
    int range = static_cast<int>(sqrt(n));
    for (int i = 2; i <= range; i++) {
        if (n % i == 0) {
            if (indexArr[n / i] != -1) {
                score[indexArr[n / i]]++;
                score[idx]--;
            }
            if (i != n / i && indexArr[i] != -1) {
                score[indexArr[i]]++;
                score[idx]--;
            }
        }
    }
}