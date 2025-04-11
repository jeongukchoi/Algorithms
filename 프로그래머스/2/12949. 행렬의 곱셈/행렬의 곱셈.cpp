#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.reserve(arr1.size() + 1);

    for (int i = 0; i < arr1.size(); ++i)
    {
        vector<int> NewRow;
        NewRow.reserve(arr2.at(0).size() + 1);
        for (int j = 0; j < arr2.at(0).size(); ++j)
        {
            int sum = 0;
            for (int k = 0; k < arr2.size(); ++k)
            {
                sum += arr1.at(i).at(k) * arr2.at(k).at(j);
            }
            NewRow.push_back(sum);
        }
        answer.push_back(NewRow);
    }
        
    return answer;
}