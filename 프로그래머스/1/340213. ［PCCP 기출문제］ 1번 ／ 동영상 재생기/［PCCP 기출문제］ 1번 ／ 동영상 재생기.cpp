#include <string>
#include <vector>

using namespace std;
string formatTime(int);

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // initial position
    int posMin = stoi(pos.substr(0, 2));
    int posSec = stoi(pos.substr(pos.size()-2));
    int posInSeconds = posMin * 60 + posSec;
    
    // opening start position
    int opStartMin = stoi(op_start.substr(0,2));
    int opStartSec = stoi(op_start.substr(op_start.size()-2));
    int opStartInSeconds = opStartMin * 60 + opStartSec;
    
    // opening end position
    int opEndMin = stoi(op_end.substr(0,2));
    int opEndSec = stoi(op_end.substr(op_end.size()-2));
    int opEndInSeconds = opEndMin * 60 + opEndSec;
    
    // video end position
    int vidEndMin = stoi(video_len.substr(0,2));
    int vidEndSec = stoi(video_len.substr(video_len.size()-2));
    int vidEndInSeconds = vidEndMin * 60 + vidEndSec;
    
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