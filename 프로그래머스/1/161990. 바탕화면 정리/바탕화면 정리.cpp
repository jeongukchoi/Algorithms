#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int top = -1;
    int bottom = -1;
    int left = -1;
    int right = -1;
    for (int i = 0; i < wallpaper.size(); i++)
    {
        size_t found = wallpaper[i].find("#");
        if (found != string::npos)
        {
            if (top == -1) top = i;
            bottom = i;
            
            int foundInt = static_cast<int>(found);
            if (foundInt < left || left == -1) left = foundInt;
            
            int rfound = static_cast<int>(wallpaper[i].rfind("#"));
            if (rfound > right) right = rfound;
            
        }
    }
    
    answer.push_back(top);
    answer.push_back(left);
    answer.push_back(bottom + 1);
    answer.push_back(right + 1);
    
    return answer;
}