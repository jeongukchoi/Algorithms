#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for (int i = 0; i < progresses.size(); ++i)
    {
        int remainderCheck = (100 - progresses[i]) % speeds[i] > 0;
        q.push((100 - progresses[i]) / speeds[i] + remainderCheck);
    }

    while (!q.empty())
    {
        int count = 1;
        int curr = q.front();
        q.pop();

        while (curr >= q.front() && !q.empty()) {
            q.pop();
            count++;
        }

        answer.push_back(count);
    }
    
    return answer;
}