#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a == b) return a;
    
    int start, end;
    if (a > b) {
        start = b;
        end = a;
    } else {
        start = a;
        end = b;
    }
    
    while (start != end + 1) {
        answer += start;
        start++;
    }
    
    return answer;
}