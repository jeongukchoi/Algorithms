#include <string>
#include <vector>

using namespace std;


int recursion(string s) {
    if (s.length() <= 1) return 1;
    
    char x = s[0];
    int same = 0;
    int different = 0;

    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == x) same++;
        else different++;
        
        if (same > 0 && same == different)
            return 1 + recursion(s.substr(i+1));
    }
    return 1;
}

int solution(string s) {
    return recursion(s);
}