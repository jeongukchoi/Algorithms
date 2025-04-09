#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    
    if (citations.at(n-1) <= 1) return citations.at(n-1);
    
    for (int i = n - 1; i >= 0; --i) {
        if (n - i > citations.at(i)) return n - i - 1;
        if (n - i == citations.at(i)) return n - i;
    }
    
    return citations.at(0) > n ? n : n - 1;
}