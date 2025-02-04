#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    unordered_map<int, string> rankMap;
    for (int i = 0; i < players.size(); i++) rankMap[i] = players[i];
    
    unordered_map<string, int> nameMap;
    for (int i = 0; i < players.size(); i++) nameMap[players[i]] = i;
    
    for (string s : callings)
    {
        int rank = nameMap[s];
        string temp = rankMap[rank-1];
        rankMap[rank-1] = s;
        rankMap[rank] = temp;
        nameMap[s] = rank-1;
        nameMap[temp] = rank;
    }
    
    for (int i = 0; i < players.size(); i++) answer.push_back(rankMap[i]);
    
    return answer;
}