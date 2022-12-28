//TC: O(n*100) , MC: O(n)
//here n = strings length

//TC: O(n*100) , MC: O(n)
//here n = strings length 

class Solution {
public:
    static const long long BASE = 997;
    static const long long MOD = 101103107109113LL;

    long long hash_func(string word)
    {
        long long H = 1;

            for(auto ch : word)
            {
                H *= BASE + ch;
                if( H >= MOD ) H %= MOD; 
            }

        return H;
    }

    vector<vector<string>> groupAnagrams(vector<string>& str) {
        
        unordered_map <long long, vector<string>> map_strings;    
        vector <vector<string>> groupAnagrams;

        int len = str.size();
        string word;
        
        for(int i=0; i < len; i++)
        {
            word = str[i];
            
            long long hash_value = hash_func(word);

            map_strings[hash_value].push_back(word);
        }
        
        for(auto &anagrams : map_strings)
        {
            groupAnagrams.push_back(anagrams.second);
        }

        return groupAnagrams;
        
    }
};
