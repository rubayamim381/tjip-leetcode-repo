//approach 1: Sliding window
//TC: O(n) MC: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> freq (256, 0);

        int Left_pntr = 0, Right_pntr = 0, maxLen = 0, dupCnt = 0, kAllowed = 1;
        int str_len = s.size();

        while (Right_pntr < str_len)
        {
            char Right_ch = s[Right_pntr];
            freq[Right_ch]++;

            if (freq[Right_ch] > kAllowed)
                dupCnt++;

            while (dupCnt > 0)
            {
                char Left_ch = s[Left_pntr]++;
                freq[Left_ch]--;

                if ( freq[Left_ch] == kAllowed )
                    dupCnt--;
                Left_pntr++;
            }

            maxLen = max(maxLen, (Right_pntr - Left_pntr + 1));
            Right_pntr++;
        }

        return maxLen;
    }
};
