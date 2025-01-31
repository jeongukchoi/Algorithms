#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> burgers;
    
    for (int i : ingredient)
    {
        burgers.push_back(i);
        
        int j = burgers.size() - 4;
        if (j < 0) continue;
        if (burgers[j] == 1 && burgers[j+1] == 2 && burgers[j+2] == 3 && burgers[j+3] == 1) {
            answer++;
            for (int k = 0; k < 4; k++) burgers.pop_back();
        }
    }
        
    return answer;
}