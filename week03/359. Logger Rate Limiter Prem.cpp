//tc = O(1), MC=O(n*m)
//n = number of messages, m = number of message's length
class Logger {
public:

    unordered_map<string, int> log_msg;

    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string msg) {

        //compare with previous msg timestamp
        if(log_msg.count(msg) && timestamp < log_msg[msg])
            return false;

        log_msg[msg] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
