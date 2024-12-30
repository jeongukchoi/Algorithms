#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int sign = 1;
    
    if (!isdigit(s[0])) {
        if (s[0] == '-') sign = -1;
        s = s.substr(1, s.length());
    }
    return sign * stoi(s);
}