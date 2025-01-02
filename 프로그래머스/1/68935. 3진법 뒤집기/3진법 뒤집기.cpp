#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    string reversed = "";
    int curr = n;
    while (curr > 2) {
        reversed += to_string(curr % 3);
        curr /= 3;
    }
    reversed += to_string(curr);
    
    unsigned int i = 0, answer = 0;
    unsigned long long curr2 = stoll(reversed);
    while (curr2) {
        answer += curr2 % 10 * pow(3, i);
        curr2 /= 10;
        i++;
    }
    
    return answer;
}