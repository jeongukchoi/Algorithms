#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (flag && c >= 'a' && c <= 'z') {
            answer += c + ('A' - 'a');
        }
        else if (!flag && c >= 'A' && c <= 'Z')
        {
            answer += c + ('a' - 'A');
        }
        else
        {
            answer += c;
        }
        flag = c == ' ';
    }
    
    return answer;
}