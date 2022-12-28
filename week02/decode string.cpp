//tc:O(n), MC:O(n)
class Solution {
public:
    string decodeString(string s) {

        stack <pair<string, int>> decoded_str_stk;
        decoded_str_stk.push({"", 1});
        int str_count = 0;

        for(auto ch : s)
        {
            if(isdigit(ch))
                str_count = (str_count * 10) + (ch - '0');

            else if(ch == '[')
            {
                decoded_str_stk.push({"", str_count});
                str_count = 0;
            }

            else if(ch == ']')
            {
                string str = decoded_str_stk.top().first;
                int str_count = decoded_str_stk.top().second;
                decoded_str_stk.pop();

                while(str_count--)
                {
                    decoded_str_stk.top().first += str;
                }
            }

            else
            {
                decoded_str_stk.top().first.push_back(ch);
            }
        }

        return decoded_str_stk.top().first;
    }

    //example: 3[abc2[d]]
    //at stack top ["",0]
    //for 1st opening bracket, at stack top ["a",3]["",0]
    //for 1st opening bracket, at stack top ["ab",3]["",0]
    //for 1st opening bracket, at stack top ["abc",3]["",0]
    //for 2nd opening bracket, at stack top ["d",2]["abc",3]["",0]


    //for 2nd closing bracket, at stack top ["abcdd",3]["",0]
    //for 1st closing bracket, at stack top ["abcddabcddabcdd",0]

};
