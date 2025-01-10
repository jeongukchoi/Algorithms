#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    const vector<int> monthToDays({0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335});
    const vector<string> whatDay({"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"});
    
    int deltaDays = monthToDays[a - 1] + b - 1;
    auto it = whatDay.begin() + 4;
    for (int i = 0; i < deltaDays % 7; i++)
    {
        it++;
        if (it == whatDay.end()) it = whatDay.begin();
    }
    
    return *it;
}