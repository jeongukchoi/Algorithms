#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    int m = max(a, b);
    int n = min(a, b);
    
    while (m % n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return n;
}

int solution(vector<int> arr) {
    int answer = 0;
    
    if (arr.size() < 2) return arr[0];
    
    // 최소공배수 = 두 수의 곱 / 최대공약수
    int a = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int b = arr[i];
        int LCM = a * b / GCD(a, b);
        a = LCM;
    }
    
    return a;
}