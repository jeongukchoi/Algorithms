#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    // 소인수분해
    set<int> primeFactors;
    for (int n : arr)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            while (n % i == 0)
            {
                primeFactors.insert(i);
                n /= i;
            }
        }
        if (n > 1) primeFactors.insert(n);
    }
    
    // product = 중복되지 않는 소인수들의 곱
    int product = accumulate(primeFactors.begin(), primeFactors.end(), 1, multiplies<int>());
    
    // 최소공배수 = product * i
    int i = 1;
    while (true)
    {
        bool flag = true;
        for (int n : arr)
        {
            if (product * i % n != 0)
            {
                flag = false;
            }
        }
        if (flag) {
            answer = product * i;
            break;
        }
        i++;
    }
    
    return answer;
}