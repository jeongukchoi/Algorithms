#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(long long i, long long j) { return i > j; }

long long solution(long long n) {
    string nStr = to_string(n);
    sort(nStr.begin(), nStr.end(), compare);
    return stoll(nStr);
}

