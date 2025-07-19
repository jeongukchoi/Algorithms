#include <bits/stdc++.h>

using namespace std;

int solution(int n, int w, int num) {
    int TopRowIndex = (n-1) / w;
    int TopEndColIndex = (n-1) % w;
    int TargetRowIndex = (num-1) / w;
    int TargetColIndex = (num-1) % w;
    
    bool IsTopRowRtoL = TopRowIndex % 2;
    bool IsTargetRowRtoL = TargetRowIndex % 2;
    
    bool IsBoxOnTop;
    if (IsTopRowRtoL == IsTargetRowRtoL)
    {
        IsBoxOnTop = TargetColIndex <= TopEndColIndex;
    }
    else
    {
        IsBoxOnTop = TargetColIndex >= w - 1 - TopEndColIndex;
    }

    return TopRowIndex - TargetRowIndex + IsBoxOnTop;
    
}