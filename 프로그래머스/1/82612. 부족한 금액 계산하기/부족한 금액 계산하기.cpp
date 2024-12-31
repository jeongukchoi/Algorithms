using namespace std;

long long solution(int price, int money, int count)
{
    long long totalPrice = 0;
    for (int i = 1; i <= count; i++) {
        totalPrice += i * price;
    }
    return totalPrice < money ? 0 : totalPrice - money;
}