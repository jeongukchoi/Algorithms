#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

string solution(string s) {
    size_t start = -1;
    string curr = s;
    int currMax = INT_MIN;
    int currMin = INT_MAX;
    
    do {
        curr = curr.substr(start + 1);
        int currInt = stoi(curr);
        currMax = max(currMax, currInt);
        currMin = min(currMin, currInt);
        start = curr.find(" ");
    } while (start != string::npos && start < curr.length() - 1);
    
    return to_string(currMin) + " " + to_string(currMax);
}