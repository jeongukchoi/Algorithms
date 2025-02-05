#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_set<string> reportSet;
    for (const string& s : report) reportSet.insert(s);
    
    unordered_map<string, vector<string>> reportMap;
    unordered_map<string, int> reportCountMap;
    for (const string& s : reportSet)
    {
        size_t pos = s.find(" ");
        string reporter = s.substr(0, pos);
        string reported = s.substr(pos + 1);
        
        reportMap[reported].push_back(reporter);
        reportCountMap[reported] += 1;
    }
    
    unordered_map<string, int> mailCountMap;
    for (const auto& reportCount : reportCountMap)
    {
        if (reportCount.second >= k)
        {
            for (const string& reporter : reportMap[reportCount.first])
            {
                mailCountMap[reporter] += 1;
            }
        }
    }
    
    for (string id : id_list) answer.push_back(mailCountMap[id]);
    
    return answer;
}