#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int discountSize = discount.size();

    for (int i = 0; i < discountSize; i++) {
        if (discountSize - i < 10) break;
        
        unordered_map<string, int> discountMap;
        for (int j = i; j < i + 10; j++)
            discountMap[discount[j]]++;
        
        bool flag = true;
        for (int i = 0; i < want.size(); i++) {
            if (discountMap[want[i]] < number[i]) {
                flag = false;
                break;
            }
        }
        
        if (flag) answer++;
    }
    return answer;
}