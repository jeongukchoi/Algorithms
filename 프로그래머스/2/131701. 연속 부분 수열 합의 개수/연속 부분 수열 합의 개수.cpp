#include <vector>
#include <set>
#include <iostream>

using namespace std;

int getSum(vector<int> v, size_t start, size_t end) {
    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += v[i % v.size()];    
    return sum;
}

int solution(vector<int> elements) {
    int answer = 0;
    set<int> results;
    
    // partial sequence length i = 0 ~ elements.size()-1
    for (int i = 0; i < elements.size(); i++) {
        // start position j
        for (int j = 0; j < elements.size(); j++) {
            // sum elements[j] ~ elements[j+i(should circle back to 0)]
            results.insert(getSum(elements, j, j+i));
        }
    }
    return results.size();
}