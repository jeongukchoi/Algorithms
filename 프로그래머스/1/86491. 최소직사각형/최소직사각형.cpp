#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int longerSideMax = 0;
    int shorterSideMax = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] >= sizes[i][1]) {
            if (sizes[i][0] > longerSideMax) longerSideMax = sizes[i][0];
            if (sizes[i][1] > shorterSideMax) shorterSideMax = sizes[i][1];
        } else {
            if (sizes[i][1] > longerSideMax) longerSideMax = sizes[i][1];
            if (sizes[i][0] > shorterSideMax) shorterSideMax = sizes[i][0];
        }
    }
    
    return longerSideMax * shorterSideMax;
}