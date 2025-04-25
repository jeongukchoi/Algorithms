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
        // 큐에서 프로세스 꺼내기
        int curr = processes.front();
        processes.pop();
        
        // 우선순위가 가장 높아 실행된 경우
        if (curr >= *priorities.rbegin())
        {
            // 실행 횟수 증가 및 priorities의 최댓값 pop
            ++exec;
            priorities.pop_back();
            // 꺼낸 프로세스가 목표 프로세스인 경우 몇번째 실행인지 반환
            if (location <= 0) return exec;
        }
        // 우선순위가 낮아 다시 큐에 넣은 경우
        else
        {
            processes.push(curr);
            // 꺼낸 프로세스가 목표 프로세스인 경우 location 변경
            if (location <= 0) location = processes.size();
        }
        --location;
    }
    
    return exec;
}