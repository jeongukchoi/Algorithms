#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    
    if (n == 1) return 0;
    
    do {
        if (answer >= 500) return -1;
        
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        ++answer;
    } while (n != 1);
    
    return answer;
}