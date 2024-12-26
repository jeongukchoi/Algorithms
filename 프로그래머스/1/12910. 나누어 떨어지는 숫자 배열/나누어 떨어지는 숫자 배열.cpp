#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    int count = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        int curr = *it;
        if (curr % divisor == 0) {
            count++;
            answer.push_back(curr);
        }
    }
    
    if (count == 0) {
        answer.push_back(-1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}