#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.length() == 4 || s.length() == 6) {
        for (size_t i = 0; i < s.length(); i++) {
            if (!isdigit(s[i])) {
                answer = false;
                break;
            } 
        }
    } else {
        answer = false;
    }
    return answer;
}