#include <string>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
    while (a % b) { // loop until remainder is 0
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return b;
}

vector<int> solution(int n, int m) {
    int gcd = getGCD(n, m);
    int lcm = n * m / gcd;
    vector<int> answer = {gcd, lcm};
    return answer;
}