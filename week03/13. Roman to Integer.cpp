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
            char next_key_char = s[i+1], key_char = s[i];

            if (roman[key_char] < roman[next_key_char])
                total_value -= roman[key_char];
            else
                total_value += roman[key_char];
        }

        return total_value;

        //for example
        //MCMXCIV
        //total_value = 0 + last character which is V = 5
        //loop from 'I' to 'M' :
            //IV = total_value - I = 5-1 =4
            //CIV = total_value + C = 4+100 = 104
            //XCIV = total_value - X = 104-10 = 94
            //MXCIV = total_value + M = 94+1000 = 1094
            //CMXCIV = total_value - C = 1094-100 = 994
            //MCMXCIV = total_value - M = 994+1094 = 1994
    }
};
