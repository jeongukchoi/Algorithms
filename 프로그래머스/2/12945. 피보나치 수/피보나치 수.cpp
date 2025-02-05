#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    unsigned long long fNminus2 = 0;
    unsigned long long fNminus1 = 1;
    unsigned long long fN = 1;
    
    for (int i = 2; i <= n; i++)
    {
        fN = (fNminus1 + fNminus2) % 1234567;
        fNminus2 = fNminus1;
        fNminus1 = fN;
    }
    
    return fN;
}