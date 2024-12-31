#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int middle = s.length() / 2;
    if (s.length() % 2 == 0) {
        answer = s[middle-1];
        answer += s[middle];
    } else {
        answer = s[middle];
    }
    return answer;
}