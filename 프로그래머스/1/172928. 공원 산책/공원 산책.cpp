#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int SRow, SCol;
    for (int i = 0; i < park.size(); i++)
    {
        size_t found = park[i].find('S');
        if (found != string::npos)
        {
            SRow = i;
            SCol = (int) found;
            break;
        }
    }
    
    int CurrRow = SRow;
    int CurrCol = SCol;
    int Width = park[0].length();
    int Height = park.size();
    for (int i = 0; i < routes.size(); i++)
    {
        char op = routes[i][0];
        int n = routes[i][2] - '0';
        switch (op)
        {
            case 'E':
                if (CurrCol + n < Width)
                {
                    bool FoundX = false;
                    for (int i = CurrCol; i <= CurrCol + n; i++)
                    {
                        if (park[CurrRow][i] == 'X')
                        {
                            FoundX = true;
                            break;
                        }
                    }
                    if (!FoundX) CurrCol += n;
                }
                break;
                
            case 'W':
                if (CurrCol - n >= 0)
                {
                    bool FoundX = false;
                    for (int i = CurrCol; i >= CurrCol - n; i--)
                    {
                        if (park[CurrRow][i] == 'X')
                        {
                            FoundX = true;
                            break;
                        }
                    }
                    if (!FoundX) CurrCol -= n;
                }
                break;
                
            case 'N':
                if (CurrRow - n >= 0)
                {
                    bool FoundX = false;
                    for (int i = CurrRow; i >= CurrRow - n; i--)
                    {
                        if (park[i][CurrCol] == 'X')
                        {
                            FoundX = true;
                            break;
                        }
                    }
                    if (!FoundX) CurrRow -= n;
                }
                break;
                
            case 'S':
                if (CurrRow + n < Height)
                {
                    bool FoundX = false;
                    for (int i = CurrRow; i <= CurrRow + n; i++)
                    {
                        if (park[i][CurrCol] == 'X')
                        {
                            FoundX = true;
                            break;
                        }
                    }
                    if (!FoundX) CurrRow += n;
                }
                break;
        }
    }
    answer.push_back(CurrRow);
    answer.push_back(CurrCol);
    return answer;
}