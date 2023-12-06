#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int a, b;
        cin >> a >> b;

        int A, B;
        A = max(a, b);
        B = min(a, b);
        
        // 최소공배수
        while (true) {
            if (A % a == 0 && A % b == 0) {
                cout << A << " ";
                break;
            }
            A++;
        }

        // 최대공약수
        for (int i = B; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
                cout << i << "\n";
                break;
            }
        }

    }

}