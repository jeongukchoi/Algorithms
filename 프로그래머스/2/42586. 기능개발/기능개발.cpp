#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> remainingDays;
    for (int i = 0; i < progresses.size(); ++i)
    {
        int remainderCheck = (100 - progresses[i]) % speeds[i] > 0;
        remainingDays.push_back((100 - progresses[i]) / speeds[i] + remainderCheck);
    }

    for (int i = 0; i < remainingDays.size(); )
    {
        int days = remainingDays[i];
        for (int j = i; j < remainingDays.size(); ++j)
        {
            cout << "subtract " << remainingDays[i] << " from " << remainingDays[j] << endl;
            remainingDays[j] -= days;
        }
        
        int count = 0;
        for (int j = i; j < remainingDays.size(); ++j)
        {
            if (remainingDays[j] > 0) break;
            count++;
        }
        answer.push_back(count);
        i += count;
    }
    
    return answer;
}