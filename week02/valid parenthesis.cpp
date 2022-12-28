//TC: O(n), MC: O(1)
class Solution {
public:
    bool isValid(string& s) {
        stack <char> stk;
        int len = s.size();

        for(int i=0; i<len; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);

            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
                {
                    if(stk.empty())
                        return false;

                    else if(s[i] == ')' && stk.top() != '(')
                        return false;

                    else if(s[i] == '}' && stk.top() != '{')
                        return false;

                    else if(s[i] == ']' && stk.top() != '[')
                        return false;

                    else stk.pop();
                }
        }

        return (stk.empty());

    }
};
