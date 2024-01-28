#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    // 오늘 파기해야 할 개인정보 번호
    // 모든 달은 28일까지
    int t_year = stoi(today.substr(0,4));
    int t_month = stoi(today.substr(5,7));
    int t_day = stoi(today.substr(8,10));
    
    vector<int> answer;
    
    for(int i=0; i<privacies.size(); i++){
        char c1 = privacies[i].at(11);
        int term;
        
        for(int k=0; k<terms.size(); k++){
            char c2 = terms[k].at(0);
            if(c1==c2){
                term = stoi(terms[k].substr(2,terms[k].length()));
                break;
            }
        }

        int year = stoi(privacies[i].substr(0,4));
        int month = stoi(privacies[i].substr(5,7));
        int day = stoi(privacies[i].substr(8,10));
        
        month += term;
        while(month > 12){
            year++;
            month -= 12;
        }
        
        if(t_year > year){
            answer.push_back(i+1);
        } 
        else if(t_year == year){
            if(t_month > month){
                answer.push_back(i+1);
            }
            else if(t_month == month){
                if(t_day >= day){
                    answer.push_back(i+1);
                }
            }
        }
    }
    
    
    return answer;
}