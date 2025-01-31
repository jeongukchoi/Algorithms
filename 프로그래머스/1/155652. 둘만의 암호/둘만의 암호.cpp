#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (char c : s)
    {
        char newChar = c;
        
        for (int i = 0; i < index; i++)
        {
            newChar++;
            if (newChar > 'z') newChar = newChar - 'z' - 1 + 'a';
            if (skip.find(newChar) != string::npos) i--;
        }
        answer += newChar;
    }
    
    return answer;
}