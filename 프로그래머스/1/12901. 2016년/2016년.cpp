#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    const vector<int> daysInMonth({31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30});
    const vector<string> whatDay({"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"});
    
    int totalDays = b - 1;
    for (int i = 0; i < a - 1; i++) {
        totalDays += daysInMonth[i];
    }
    
    return whatDay[(totalDays + 4) % 7];
}