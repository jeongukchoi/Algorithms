#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    int zeroCount = 0;
    int convertCount = 0;
    
    while (s != "1")
    {
        // 1. 0 제거 / 카운트 증가
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                s.erase(i, 1);
                i--;
                zeroCount++;
            }
        }
        
        // 2. 길이를 2진법으로 변환 / 카운트 증가
        int len = s.length();
        s = bitset<18>(len).to_string();
        s.erase(0, s.find_first_not_of('0'));
        convertCount++;
    }
    
    return {convertCount, zeroCount};
}