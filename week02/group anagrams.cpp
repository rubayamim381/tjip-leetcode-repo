//TC: O(n*100) , MC: O(n)
//here n = strings length

class Solution {
public:
    static const long long base = 997;
    static const long long mod = 101103107109113LL;

    vector<vector<string>> groupAnagrams(vector<string>& str) {

        unordered_map <long long, vector<string>> map_strings;
        vector <vector<string>> groupAnagrams;

        int len = str.size();
        string word;

        for(int i=0; i < len; i++)
        {
            word = str[i];
            long long H = 1;

            for(auto ch : word)
            {
                H *= base + ch;
                if( H >= mod ) H %= mod;
            }

            map_strings[H].push_back(word);
        }

        for(auto &anagrams : map_strings)
        {
            groupAnagrams.push_back(anagrams.second);
        }

        return groupAnagrams;

    }
};
