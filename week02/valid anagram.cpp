//Approach 1: String hash
//TC: O(n), MC: O(1)
class Solution {
public:

    //base = a safe prime number as we take the string from 1-26
    static const int base = 997;
    static const long long mod = 101103107109113LL;

    long long getHash( string &s )
    {
        long long str_hash = 1;
        for( auto ch : s )
        {
            str_hash *= ( base + ch - 'a');

            if( str_hash >= mod )
                str_hash %= mod;
        }

        return str_hash;
    }
    bool isAnagram(string s, string t) {
        return getHash(s) == getHash(t);
    }
};

//Approach 2: frequency
//TC: O(n), MC: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int> freq(26, 0);

        //count individual character frequency
        for( auto ch : s )
            freq[ch - 'a']++;

        //subtract individual character frequency
        for( auto ch : t )
            freq[ch - 'a']--;

        for(int i=0; i<26; i++)
            if(freq[i] != 0) return 0;

        return 1;
    }
};

