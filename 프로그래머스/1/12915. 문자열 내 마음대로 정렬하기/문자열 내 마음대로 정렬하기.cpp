#include <string>
#include <vector>
#include <algorithm>

int index = 0;
using namespace std;

bool comp(string s1, string s2) {
    if (s1[index] == s2[index]) {
        return s1.compare(s2) < 0;
    } else {
        return s1[index] < s2[index];
    }
}

vector<string> solution(vector<string> strings, int n) {
    index = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}

