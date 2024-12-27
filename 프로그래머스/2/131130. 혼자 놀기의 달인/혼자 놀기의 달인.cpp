#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int best = 0, secondBest = 0;
    
    // vector of opened boxes
    vector<int> open = {};
    
    // number of opened boxes for each group
    vector<int> counts = {};

    // iterate through the cards
    for (int i = 0; i < cards.size(); i++) {
        int count = 0; // counts the number of opened boxes in current group
        int curr = i;
        
        // keep opening boxes until it finds the box in vector 'open'
        while (find(open.begin(), open.end(), cards[curr]) == open.end()) {
            open.push_back(cards[curr]);
            curr = cards[curr] - 1;
            count++;
        }
        
        // record the number of opened boxes in current group
        counts.push_back(count);
    }
    
    // pick the two best counts
    for (int num : counts) {
        if (num > best) {
            secondBest = best;
            best = num;
        } else if (num > secondBest) {
            secondBest = num;
        }
    }
    
    return best * secondBest;
}