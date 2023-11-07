#include <iostream>

using namespace std;

int main()
{
    
    int N;
    cin >> N;
    
    int score[N];
    
    for(int i=0; i<N; i++){
        cin >> score[i];
    }
    
    int sum = 0;
    int max = 0;
    
    for(int i=0; i<N; i++){
        sum += score[i];
        if(max<score[i]){
            max = score[i];
        }
    }
    
    double res = sum*100.0/max/N;
    cout << res;
    
}