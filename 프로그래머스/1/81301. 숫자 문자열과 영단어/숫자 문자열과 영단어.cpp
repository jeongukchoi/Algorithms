#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string s) {
    long long answer = 0;
    vector<int> numbers;
    
    unordered_map<string, int> wordNum = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    
    for (int i = 0; i < s.length(); i++) {
        // iterate and check
        if (isdigit(s[i])) {
            int num = s[i] - '0';
            numbers.push_back(num);
        } else {
            auto it = wordNum.find(s.substr(i, 3));
            if (it != wordNum.end()) {
                numbers.push_back(it->second);
                i += 2;
                continue;
            }

            it = wordNum.find(s.substr(i, 4));
            if (it != wordNum.end()) {
                numbers.push_back(it->second);
                i += 3;
                continue;
            }

            it = wordNum.find(s.substr(i, 5));
            if (it != wordNum.end()) {
                numbers.push_back(it->second);
                i += 4;
                continue;
            }
        }
    }
    
    for (int i = 0; i < numbers.size(); i++)
        answer += numbers[numbers.size() - 1 - i] * pow(10, i);
    
    return answer;
}