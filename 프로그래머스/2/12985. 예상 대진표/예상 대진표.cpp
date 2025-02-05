using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while (true)
    {
        answer++;
        // a 가 짝수이면 b 는 a -1 / b 가 짝수이면 a 는 b - 1
        if ((a % 2 == 0 && b == a - 1) || (b % 2 == 0 && a == b - 1)) break;
        a = (a + (a % 2)) / 2;
        b = (b + (b % 2)) / 2;
    }
    return answer;
}