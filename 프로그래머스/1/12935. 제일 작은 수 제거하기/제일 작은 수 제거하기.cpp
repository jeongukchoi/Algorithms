#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.empty() || arr.size() <= 1) return {-1};
    
    auto min = arr.begin();
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (*it < *min) min = it;
    }
    arr.erase(min);
    
    return arr;
}