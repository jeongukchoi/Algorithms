#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<int, int> XCount, YCount, MatchCount;
    
    // X와 Y에 각각 나타나는 정수의 갯수 세기
    for (auto it = X.begin(); it != X.end(); it++) XCount[*it - '0']++;
    for (auto it = Y.begin(); it != Y.end(); it++) YCount[*it - '0']++;
    
    // YCount 에서 XCount 의 key 를 찾아 MatchCount 에 등록
    for (auto it = XCount.begin(); it != XCount.end(); it++) {
        auto CompIt = YCount.find(it->first);
        
        // 없으면 패스
        if (CompIt == YCount.end()) continue;
        
        // 있으면 갯수가 작거나 같은 쪽으로 등록
        if (it->second <= CompIt->second) {
            MatchCount[it->first] = it->second;
        }
        else {
            MatchCount[CompIt->first] = CompIt->second;
        }
    }
    
    // MatchCount 에 등록된 정수가 없으면 "-1"
    if (MatchCount.empty()) return "-1";
    
    // MatchCount 오름차순 정렬되어 있으므로 마지막 원소가 0이면 "0"
    if (MatchCount.rbegin()->first == 0) return "0";
    
    // MatchCount 거꾸로 순회하며 갯수만큼 숫자를 string 에 추가
    for (auto rit = MatchCount.rbegin(); rit != MatchCount.rend(); rit++) {
        string s(rit->second, rit->first + '0');
        answer += s;
    }
    
    return answer;
}