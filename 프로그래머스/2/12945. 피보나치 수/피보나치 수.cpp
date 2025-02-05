
using namespace std;

int solution(int n) {
    unsigned int fNminus2 = 0;
    unsigned int fNminus1 = 1;
    unsigned int fN = 1;
    
    for (int i = 2; i <= n; i++)
    {
        fN = (fNminus1 + fNminus2) % 1234567;
        fNminus2 = fNminus1;
        fNminus1 = fN;
    }
    
    return fN;
}