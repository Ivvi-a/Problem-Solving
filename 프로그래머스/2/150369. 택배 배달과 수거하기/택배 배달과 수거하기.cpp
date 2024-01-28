#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d = 0;
    int p = 0;
    int dist = n;
    
    for(int i=n-1; i>=0; i--){
        int now_d = deliveries[i];
        int now_p = pickups[i];
        
        // (0,0) 인 경우
        if(now_d == 0 && now_p == 0){
            if(d == 0 && p == 0){
                dist--;
            }
            continue;
        }
        // 더할 값이 있는 경우
        else{
            d += now_d;
            p += now_p;
            while(d > cap || p > cap){
                answer += 2*dist;
                d -= cap;
                p -= cap;
                // d = max(0, d - cap);
                // p = max(0, p - cap);
                dist = i+1;
            }
        }
    }
    
    if(d > 0 || p > 0){
        answer += 2*dist;
    }
    
    return answer;
}