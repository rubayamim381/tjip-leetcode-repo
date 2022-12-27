//approach 1
//tc: O(n), mc: O(1)

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int last_idx = s.length()-1, total_value = 0;

        char last_ch = s[last_idx];
        total_value += roman[last_ch];

        for(int i = last_idx-1; i >= 0; --i)
        {
            char after_key = s[i+1], key = s[i];

            if ( roman[key] < roman[after_key] )
                total_value -= roman[key];
            else
                total_value += roman[key];
        }

        return total_value;

        //for example
        //MCMXCIV
        //total_value = roman[last_ch] = 5
        //loop from 'I' to 'M' :
        //IV = total_value - I = 5-1 =4
        //CIV = total_value + C = 100+4 = 104
        //XCIV = total_value - X = 104-10 = 94
        //MXCIV = total_value + M = 1000+94 = 1094
        //CMXCIV = total_value - C = 1094-100 = 994
        //MCMXCIV = total_value - M = 1094+994 = 1994
    }
};
