#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int MatchCount = 0;
    int ZeroCount = 0;
    
    for (int i : lottos) {
        if (i == 0) {
            ZeroCount++;
            continue;
        }
        
        auto findIt = find(win_nums.begin(), win_nums.end(), i);
        if (findIt != win_nums.end()) {
            MatchCount++;
        }
    }
    // 순위 = 7 - 일치 갯수 (일치 갯수가 0이면 6등)
    answer.push_back(MatchCount == 0 && ZeroCount == 0 ? 6 : 7 - (MatchCount + ZeroCount));
    answer.push_back(MatchCount == 0 || MatchCount == 1 ? 6 : 7 - MatchCount);
    
    return answer;
}