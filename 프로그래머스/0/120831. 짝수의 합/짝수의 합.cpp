#include <iostream>

using namespace std;

int solution(int n) {
    if (n % 2) n--;
    int total = n*(n+1) / 2;    
    return static_cast<int>(total / 2.f + n / 4.f);;
}