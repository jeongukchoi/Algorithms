#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same = 1; // first character is a match
    int different = 0;
    char x = s[0];
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == x) {
            same++;
        } else {
            different++;
        }
        
        if (same == different) {
            same = 0;
            different = 0;
            answer++;
            x = s[i + 1]; // npos if out of range
        }
    }
    
    if (same > 0) answer++;
    
    return answer;
}