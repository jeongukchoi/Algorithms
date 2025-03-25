
long long solution(int n) {
    
    if (n <= 1) return 1;
    
    long long LeapByOne = 1, LeapByTwo = 1;
    
    for (int i = 2; i <= n; i++)
    {
        long long Current = (LeapByOne + LeapByTwo) % 1234567;
        LeapByTwo = LeapByOne;
        LeapByOne = Current;
    }
    
    return LeapByOne;
}