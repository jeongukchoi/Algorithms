#include <cmath>

using namespace std;

long long solution(long long n) {
    long long root = static_cast<long long>(sqrt(n));
    long long answer = static_cast<long long>(pow(root, 2)) == n ? static_cast<long long>(pow(root+1, 2)) : -1;
    return answer;
}