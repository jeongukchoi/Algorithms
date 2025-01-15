#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> win;
    vector<int> counts = {0, 0, 0};
    int guess1[] = {1, 2, 3, 4, 5};
    int guess2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int guess3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (guess1[i % 5] == answers[i]) counts[0]++;
        if (guess2[i % 8] == answers[i]) counts[1]++;
        if (guess3[i % 10] == answers[i]) counts[2]++;
    }
    
    int max = *max_element(counts.begin(), counts.end());
    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] == max) win.push_back(i+1);
    }
    
    return win;
}