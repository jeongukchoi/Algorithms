#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    deque<string> c1(cards1.begin(), cards1.end());
    deque<string> c2(cards2.begin(), cards2.end());
    
    string answer = "";
    
    int i = 0;
    while (i < goal.size())
    {
        if (goal[i] == c1.front())
        {
            c1.pop_front();
            i++;
        }
        
        else if (goal[i] == c2.front())
        {
            c2.pop_front();
            i++;
        }
        
        else
        {
            return "No";
        }
    }
    
    return "Yes";
}