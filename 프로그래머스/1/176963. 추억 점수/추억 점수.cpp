#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    unordered_map<string, int> scoreMap;
    for (int i = 0; i < name.size(); ++i)
    {
        scoreMap[name[i]] = yearning[i];
    }
    
    vector<int> scores;
    for (int i = 0; i < photo.size(); ++i)
    {
        int sum = 0;
        for (string currName : photo[i])
        {
            sum += scoreMap[currName];
        }
        scores.push_back(sum);
    }
    return scores;
}