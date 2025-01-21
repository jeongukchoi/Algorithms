#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    
    // reserve 중 lost 에 있는 학생 우선 삭제
    for (int i = 0; i < lost.size(); i++) {
        auto it = find(reserve.begin(), reserve.end(), lost[i]);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost.erase(lost.begin() + i--);
            continue;
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        auto it = find(reserve.begin(), reserve.end(), lost[i] - 1);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost.erase(lost.begin() + i--);
            continue;
        }
        
        it = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost.erase(lost.begin() + i--);
        }
    }
    
    return n - lost.size();
}