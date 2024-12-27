using namespace std;

int solution(int num1, int num2) {
    int answer = static_cast<int>(1000 * static_cast<float>(num1) / static_cast<float>(num2));
    return answer;
}