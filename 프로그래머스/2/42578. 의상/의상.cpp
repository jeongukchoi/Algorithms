#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <numeric>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_set<string> CategorySet;
    multimap<string, string> ClothesMap;
    
    // 벡터 순회하며 multimap 에 pair 추가 및 set 에 key 추가
    for (int i = 0; i < clothes.size(); ++i)
    {
        CategorySet.insert(clothes.at(i).at(1));
        ClothesMap.insert(pair<string, string>(clothes.at(i).at(1), clothes.at(i).at(0)));
    }
    
    
    // 각 종류에 해당하는 의상 개수의 곱 누적
    int Product = 1;
    for (const auto& Category : CategorySet)
    {
        Product *= (ClothesMap.count(Category) + 1); // 해당 종류 의상을 안 입는 경우를 고려하여 +1
    }
    
    return Product - 1; // 아무 의상도 안 입는 경우를 제외하여 -1
}