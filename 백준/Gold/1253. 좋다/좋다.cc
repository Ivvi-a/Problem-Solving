#include <iostream>
#include <algorithm>
using namespace std;

int arr[2000];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        arr[i] = n;
    }

    sort(arr, arr+N); // 오름차순 정렬

    // two pointer
    int index = 0;
    int ans = 0;

    while (index < N) {
        // cout << "index: "<< index << "\n";
        // 같은 수의 개수 세기
        int cnt = 1;
        while (true) {
            if (index == N - 1) {
                break;
            }
            if (arr[index] == arr[index + 1]) {
                cnt++;
                index++;
            }
            else {
                break;
            }
        }

        // 두 수의 합으로 이루어지는지 확인
        int left = 0;
        int right = N - 1;
        int target = arr[index];

        while (left < right) {
            if (left == index) {
                left++;
                continue;
            }
            else if (right == index) {
                right--;
                continue;
            }

            int num1 = arr[left];
            int num2 = arr[right];
            if (num1 + num2 == target) {
                // cout << left << " " << right << "\n";
                ans += cnt;
                break;
            }
            else if (num1 + num2 < target) {
                left++;
            }
            else {
                right--;
            }
        }

        index++;

    }

    cout << ans;

}