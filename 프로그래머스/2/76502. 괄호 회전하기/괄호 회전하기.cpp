#include <string>
#include <vector>
#include <iostream>

using namespace std;

int isValid(const string& s);

int solution(string s) {
    if (s.length() < 4 || s.length() % 2) return 0;
    
    vector<string> rotatedS;
    for (int i = 0; i < s.length(); i++) {
        rotatedS.push_back(s);
        s = s.substr(1) + s[0];
    }
    
    int answer = 0;
    for (string r : rotatedS) answer += isValid(r);
    return answer;
}

int isValid(const string& s) {
    // keeps track of opened brackets in order of opening
    vector<char> opened;
    
    for (char c : s) {
        switch(c) {
            case '(':
            case '{':
            case '[':    
                // add to the end of 'opened'
                opened.push_back(c);
                break;
                
            case ')':
                if (opened.empty()) return 0;
                
                // last element in 'opened' needs to match / invalid if not
                if (opened[opened.size() - 1] != '(') return 0;
                
                // closed the last opened bracket - now remove it
                opened.pop_back();
                break;
                
            case '}':
            case ']':
                if (opened.empty()) return 0;
                
                // last element in 'opened' needs to match / invalid if not
                if (opened[opened.size() - 1] != static_cast<char>(c-2)) return 0;
                
                // closed the last opened bracket - now remove it
                opened.pop_back();
                break;
                
            default:
                return 0;
        }
    }
    return opened.empty();
}