#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int pos = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            pos = 0;
            continue;
        }
        
        if (pos % 2 == 0) {
            answer += toupper(s[i]);
            pos++;
        } else {
            answer += tolower(s[i]);
            pos++;
        }
    }
    
    return answer;
}