#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    
    string temp = "";
    vector<int> v;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            v.push_back(stoi(temp));
            temp.clear();
            continue;
        }
        
        temp += s[i];
    }
    
    if (!temp.empty()) v.push_back(stoi(temp));
    
    sort(v.begin(), v.end());
    
    return to_string(*v.begin()) + " " + to_string(*(v.end()-1));
}