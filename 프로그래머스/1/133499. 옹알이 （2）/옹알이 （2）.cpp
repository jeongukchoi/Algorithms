#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
        
    for (string s : babbling) {
        string temp = s;
        string last = "";
        bool flag = false;
        while (true) {
            // 남은 글자가 없으면 OK
            if (temp.empty()) {
                flag = true;
                break;
            }
        
            // 1 글자 남았으면 X
            if (temp.length() == 1) {
                break;
            }
            
            // 첫 2글자와 비교
            string FirstTwo = temp.substr(0, 2);
            
            // 마지막 발음과 같으면 X
            if (FirstTwo == last) break;
            
            // 발음할 수 있는지 체크
            if (FirstTwo == "ye") {
                temp = temp.substr(2);
                last = "ye";
                continue;
            }
            else if (FirstTwo == "ma") {
                temp = temp.substr(2);
                last = "ma";
                continue;
            }
            
            // 일치하지 않았고 마지막 2글자를 확인한 상태
            if (temp.length() == 2) break;
                        
            // 3 글자 이상 남음
            string FirstThree = temp.substr(0, 3);
            if (FirstThree == last) break;
            
            if (FirstThree == "aya") {
                temp = temp.substr(3);
                last = "aya";
                continue;
            } else if (FirstThree == "woo") {
                temp = temp.substr(3);
                last = "woo";
                continue;
            }
            
            // 전부 일치하지 않았음
            break;
        }
        
        if (flag) answer++;
    }
    
    return answer;
}