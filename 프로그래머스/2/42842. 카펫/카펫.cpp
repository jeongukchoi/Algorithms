#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int brownHeight = 3; brownHeight <= brown / 4 + 1; brownHeight++)
    {
        int brownWidth = brown / 2 + 2 - brownHeight;
        if ((brownWidth - 2) * (brownHeight - 2) == yellow)
        {
            return {brownWidth, brownHeight};
        }
    }
    
    return answer;
}