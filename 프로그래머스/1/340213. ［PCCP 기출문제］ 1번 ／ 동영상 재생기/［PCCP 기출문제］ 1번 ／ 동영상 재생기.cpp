#include <string>
#include <vector>

using namespace std;
string formatTime(int);
int getTotalSeconds(string);

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int posInSeconds = getTotalSeconds(pos);            // initial position
    int opStartInSeconds = getTotalSeconds(op_start);   // opening start position
    int opEndInSeconds = getTotalSeconds(op_end);       // opening end position
    int vidEndInSeconds = getTotalSeconds(video_len);   // video end position
    
    // iterate through commands
    for (vector<string>::iterator command = commands.begin(); command != commands.end(); command++) {
        // skip the opening if the position is within the opening
        if (posInSeconds >= opStartInSeconds && posInSeconds <= opEndInSeconds) {
            pos = op_end;
            posInSeconds = opEndInSeconds;
        }
        
        // On "prev"
        if (*command == "prev") {
            // move to start if the current position is less than or equal to 10 seconds
            if (posInSeconds <= 10) {
                posInSeconds = 0;
                pos = "00:00";
            }
            
            // 10 seconds backwards
            else {
                posInSeconds -= 10;
                pos = formatTime(posInSeconds);
            }
        }
        
        // On "next"
        else if (*command == "next") {
            // move to end if there is less than 10 seconds left
            if (vidEndInSeconds - posInSeconds <= 10) {
                posInSeconds = vidEndInSeconds;
                pos = video_len;
            }
            
            // 10 seconds forward
            else {
                posInSeconds += 10;
                pos = formatTime(posInSeconds);
            }
        }
        
        // skip the opening if the position is within the opening
        if (posInSeconds >= opStartInSeconds && posInSeconds <= opEndInSeconds) {
            pos = op_end;
            posInSeconds = opEndInSeconds;
        }
    }
    
    return pos;
}

int getTotalSeconds(string str) {
    string input = str;
    int min = stoi(input.substr(0, 2));
    int sec = stoi(input.substr(input.size()-2));
    return min * 60 + sec;
}

string formatTime(int sec) {
    string formatted = "";
    int min = sec / 60;
    sec = sec % 60;
    
    if (min < 10) {
        formatted = "0" + to_string(min) + ":";
    } else {
        formatted = to_string(min) + ":";
    }
    
    if (sec < 10) {
        formatted += "0" + to_string(sec);
    } else {
        formatted += to_string(sec);
    }
    
    return formatted;
}