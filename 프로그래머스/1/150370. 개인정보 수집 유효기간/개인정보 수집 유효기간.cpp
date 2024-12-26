#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todayY = stoi(today);
    int todayM = stoi(today.substr(5, 2));
    int todayD = stoi(today.substr(8));
    
    map<char, int> termsMap;
    for (auto it = terms.begin(); it != terms.end(); ++it) {
        const string term = *it;
        char termChar =  term.substr(0, 1)[0];
        int termMonths = stoi(term.substr(2));
        
        termsMap.insert(make_pair(termChar, termMonths));
    }
    
    for (auto it = privacies.begin(); it != privacies.end(); ++it) {
        const string info = *it;
        int infoY = stoi(info);
        int infoM = stoi(info.substr(5, 2));
        int infoD = stoi(info.substr(8));
        char infoTerm = info[11];
        
        int termM = termsMap.find(infoTerm)->second;
        
        int endY = infoY + (termM / 12);
        int endM = infoM + (termM % 12);
        if (endM > 12) {
            endY++;
            endM %= 12;
        }
        
        if (todayY > endY) {
            answer.push_back(distance(privacies.begin(), it) + 1);
        } else if (todayY == endY) {
            if (todayM > endM) {
                answer.push_back(distance(privacies.begin(), it) + 1);
            } else if (todayM == endM) {
                if (todayD >= infoD) {
                    answer.push_back(distance(privacies.begin(), it) + 1);
                }
            }
        }
        

    }
    
    return answer;
}