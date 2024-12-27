#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for (int i = 1; i < food.size(); i++) {
        int numFoodAtI = (food[i] % 2 == 0 ? food[i] : food[i] - 1);

        char c = i + '0';
        answer.insert(answer.begin() + answer.length() / 2, numFoodAtI, c);
    }
    
    answer.insert(answer.begin() + answer.length() / 2,  '0');
    
    return answer;
}