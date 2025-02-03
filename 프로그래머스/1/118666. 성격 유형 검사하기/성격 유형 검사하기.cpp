#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char, int> scores;
    
    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] > 4) scores[survey[i][1]] += choices[i] - 4;
        else if (choices[i] < 4) scores[survey[i][0]] += 4 - choices[i];
    }
    
    answer += (scores['R'] + scores['T'] * -1 >= 0 ? 'R' : 'T');
    
    answer += (scores['C'] + scores['F'] * -1 >= 0 ? 'C' : 'F');
    
    answer += (scores['J'] + scores['M'] * -1 >= 0 ? 'J' : 'M');
    
    answer += (scores['A'] + scores['N'] * -1 >= 0 ? 'A' : 'N');

    return answer;
}