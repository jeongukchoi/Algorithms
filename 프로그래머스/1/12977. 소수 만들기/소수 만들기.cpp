#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool IsPrimeNumber(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (IsPrimeNumber(nums[i] + nums[j] + nums[k])) answer++;
            }
        }
    }

    return answer;
}

