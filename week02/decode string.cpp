class Solution {
public:
    string decodeString(string s) {

        stack <pair<string, int>> DecodedStr_stk;
        DecodedStr_stk.push({"", 1});
        int str_count = 0;

        for(auto ch : s)
        {
            if(isdigit(ch))
                str_count = (str_count * 10) + (ch - '0');

            else if(ch == '[')
            {
                DecodedStr_stk.push({"", str_count});
                str_count = 0;
            }

            else if(ch == ']')
            {
                string str = DecodedStr_stk.top().first;
                int str_count = DecodedStr_stk.top().second;
                DecodedStr_stk.pop();

                while(str_count--)
                {
                    DecodedStr_stk.top().first += str;
                }
            }

            else
            {
                DecodedStr_stk.top().first.push_back(ch);
            }
        }

        return DecodedStr_stk.top().first;
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
