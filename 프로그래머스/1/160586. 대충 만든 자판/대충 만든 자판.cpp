#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> minMap;
    
    for (char c = 'A'; c != 'Z' + 1; c++) {
        int min = 0;
        for (const string& key : keymap) {
            size_t found = key.find(c);
            if (found == string::npos) continue;
            if (found + 1 < min || min == 0) min = found + 1;
        }
        minMap[c] = min;
    }
    
    for (const string& target : targets) {
        int totalNumPress = 0;

        for (char targetChar : target) {
            int numPress = minMap[targetChar];
            if (!numPress) {
                totalNumPress = -1;
                break;
            }
            totalNumPress += numPress;
        }
        answer.push_back(totalNumPress);
    }
    
    return answer;
}