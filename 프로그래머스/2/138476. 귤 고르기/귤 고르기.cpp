#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> FrequencyMap;
    
    // 등장 빈도 해시테이블로 저장
    for (int i : tangerine)
    {
        FrequencyMap[i]++;
    }
    
    vector<pair<int, int>> FrequencyVec(FrequencyMap.begin(), FrequencyMap.end());
    sort(FrequencyVec.begin(), FrequencyVec.end(), [](
        const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    });
    
    for (const pair<int, int>& p : FrequencyVec)
    {
        if (k <= 0)
        {
            return answer;
        }
        
        k -= p.second;
        answer++;
    }
    
    return answer;
}