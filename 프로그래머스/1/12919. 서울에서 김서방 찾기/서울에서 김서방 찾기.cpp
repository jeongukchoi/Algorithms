#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    int i = 0;
    for (auto it = seoul.begin(); it != seoul.end(); ++it) {
        if (*it == "Kim") {
            return answer + to_string(i) + "에 있다";
        }
        i++;
    }
    return answer;
}