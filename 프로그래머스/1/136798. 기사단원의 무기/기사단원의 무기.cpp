#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int sum = 0;
    for (int i = 1; i <= number; i++) {
        int count = 0;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                count++;
                if (pow(j, 2) != i) {
                    count++;
                }
            }
            if (count > limit) {
                count = power;
                break;
            }
        }
        sum += count;
    }
    return sum;
}