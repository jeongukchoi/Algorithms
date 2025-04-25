#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> processes {
        deque<int>(priorities.begin(), priorities.end())
    };
    sort(priorities.begin(), priorities.end());
    
    int exec = 0;
    while (!processes.empty())
    {
        int curr = processes.front();
        processes.pop();
        
        if (curr >= *priorities.rbegin())
        {
            ++exec;
            priorities.pop_back();
            if (location <= 0) return exec;
        }
        else
        {
            processes.push(curr);
            if (location <= 0) location = processes.size();
        }
        --location;
    }
    
    return exec;
}