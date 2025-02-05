#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int zeroCount = 0;
    int convertCount = 0;
    
    while (s != "1")
    {
        // 1. 0 카운트
        int currZeroCount = 0;
        for (int i = 0; i < s.size(); i++)
            currZeroCount += s[i] == '0';
        zeroCount += currZeroCount;
        
        // 2. 길이(1 카운트)를 이진법 변환 / 카운트 증가
        int oneCount = s.size() - currZeroCount;
        s.clear();
        while (oneCount) {
            char bit = (oneCount % 2) + '0';
            s = bit + s;
            oneCount /= 2;
        }
        convertCount++;
    }
    
    return {convertCount, zeroCount};
}