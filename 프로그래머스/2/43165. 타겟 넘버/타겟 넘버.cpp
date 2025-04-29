#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int index, int target, int sum, int& count) {
    if (index == numbers.size()) {
        if (sum == target)++count;
        return;
    }
    
    dfs(numbers, index + 1, target, sum + numbers[index], count);
    dfs(numbers, index + 1, target, sum - numbers[index], count);
}

int solution(vector<int> numbers, int target) {
    int count = 0;
    dfs(numbers, 0, target, 0, count);
    return count;
}
