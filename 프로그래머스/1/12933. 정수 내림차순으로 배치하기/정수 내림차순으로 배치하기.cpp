#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(long long i, long long j) { return i > j; }

long long solution(long long n) {
    vector<int> v = {};
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    
    sort(v.begin(), v.end(), compare);
    
    
    long long answer = 0;
    int i = 1;
    for(auto it = v.begin(); it != v.end(); it++) {
        answer += *it * pow(10, v.size() - i);
        i++;
    }
    
    return answer;
}

