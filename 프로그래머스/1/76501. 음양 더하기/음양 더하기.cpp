#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    auto signsIter = signs.begin();
    for (int absolute : absolutes) {
        int sign = ((*signsIter) ? 1 : -1);
        
        answer += absolute * sign;
        
        ++signsIter;
    }
    
    return answer;
}