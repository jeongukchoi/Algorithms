#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> records;
    vector<int> recordMins;
    
    records.push_back(score[0]);
    recordMins.push_back(score[0]);
    
    for (int i = 1; i < score.size(); i++) {
        if (i < k) {
            records.push_back(score[i]);
        } else {
            if (score[i] >= recordMins[i-1]) {
                auto replaceIt = find(records.begin(), records.end(), recordMins[i-1]);
                *replaceIt = score[i];
            }
        }
        recordMins.push_back(*min_element(records.begin(), records.end()));
    }
    
    return recordMins;
}