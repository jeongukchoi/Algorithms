#include <string>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<char, int> XCount, YCount, MatchCount;
    
    // X와 Y에 각각 나타나는 정수의 갯수 세기
    for (char c : X) XCount[c]++;
    for (char c : Y) YCount[c]++;
    
    // 9 ~ 0 내림차순으로 순회하며 더 적은 쪽 갯수(min)만큼 해당 정수(i)를 스트링에 추가
    for (int i = 9; i >= 0; i--) {
        int num = min(XCount[i + '0'], YCount[i + '0']);
        for (int j = 0; j < num; j++) answer += i + '0';
    }
    
    // 없으면 -1 / 첫 글자가 0이면 0
    if (answer == "") return "-1";
    if (answer[0] == '0') return "0";
    return answer;
}