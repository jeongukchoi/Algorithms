#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    while (!section.empty())
    {
        answer++;
        int start = section[0];
        for (int i = 0; i < section.size(); i++)
        {
            if (section[i] >= start && section[i] <= start+m-1)
            {
                section.erase(section.begin() + i);
                i--;
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}