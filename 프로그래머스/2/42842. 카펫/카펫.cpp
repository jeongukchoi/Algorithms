#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int widthPlusHeight = brown / 2 + 2;
    int height = 3;
    int width = widthPlusHeight - height;
    for (; height <= widthPlusHeight / 2; height++)
    {
        width = widthPlusHeight - height;
        if ((width - 2) * (height - 2) == yellow) break;
    }
    
    return {width, height};
}