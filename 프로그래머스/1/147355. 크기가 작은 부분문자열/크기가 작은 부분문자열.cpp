#include <string>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for (int i = 0; i <= t.length() - p.length(); i++) {
        string sub = t.substr(i, p.length());
        if (stoll(sub) <= stoll(p)) {
            answer++;
        }
    }
    
    return answer;
}