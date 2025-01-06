#include <string>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for(int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            continue;
        }
        
        int newCharInt = s[i] + n;
        if (s[i] <= 'Z') {
            if (newCharInt > 'Z') newCharInt -= 26;
        } else {
            if (newCharInt > 'z') newCharInt -= 26;
        }
        
        answer += static_cast<char>(newCharInt);
    }
    return answer;
}