#include <iostream>

using namespace std;

int main()
{
    
    int N;
    cin >> N;
    
    string numbers;
    cin >> numbers;
    
    int sum = 0;
    
    for(int i=0; i<N; i++){
        sum += numbers[i] - '0';
    }
    
    cout << sum;

    return 0;
}