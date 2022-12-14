// Approach 1: Recursion
// TC:  O(26 * n) = O(n), MC: O(1)

class Solution {
public:

    int max_len = 0;

    int longestSubstringHelper(const string& s, int k, int start, int end) {

        vector<int> freq(26, 0);

        for (int i = start; i < end; ++i) {
            ++freq[s[i] - 'a'];
        }

        for (int i = start; i < end;)
        {
            while (i < end && freq[s[i] - 'a'] < k)
                ++i;
            if (i == end)
                break;

            int j = i;
            while (j < end && freq[s[j] - 'a'] >= k)
                ++j;

            if (i == start && j == end)
                return (end - start);

            max_len = max(max_len, longestSubstringHelper(s, k, i, j));
            i = j;
        }
        return max_len;
    }


    int longestSubstring(string s, int k) {
        return longestSubstringHelper(s, k, 0, s.size());
    }

};
