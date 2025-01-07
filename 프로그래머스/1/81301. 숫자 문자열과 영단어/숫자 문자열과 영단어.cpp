#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string s) {
    long long answer = 0;
    
    unordered_map<string, int> wordNum = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    
    for (int i = 0; i < s.length(); i++) {
        // iterate and check
        if (isdigit(s[i])) {
            int num = s[i] - '0';
            answer = answer * 10 + num;
        } else {
            auto it = wordNum.find(s.substr(i, 3));
            if (it != wordNum.end()) {
                answer = answer * 10 + it->second;
                i += 2;
                continue;
            }

            it = wordNum.find(s.substr(i, 4));
            if (it != wordNum.end()) {
                answer = answer * 10 + it->second;
                i += 3;
                continue;
            }

            it = wordNum.find(s.substr(i, 5));
            if (it != wordNum.end()) {
                answer = answer * 10 + it->second;
                i += 4;
                continue;
            }
        }
    }

    return answer;
}