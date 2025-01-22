#include <string>

using namespace std;

int recursion(string s, int count) {
    if (s.empty()) return count;
    if (s.length() == 1) return count + 1;
    
    char x = s[0];
    int same = 0;
    int different = 0;

    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == x) same++;
        else different++;
        
        if (same > 0 && same == different){
            return recursion(s.substr(i+1), count + 1);
        }
    }
    return count + 1;
}

int solution(string s) {
    return recursion(s, 0);
}