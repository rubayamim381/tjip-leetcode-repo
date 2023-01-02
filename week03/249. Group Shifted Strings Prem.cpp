//tc: O(n*m), mc: O(n)
//n = strings length, m=word length

class Solution {
public:

    static const int BASE = 997;
    static const long long MOD = 101103107109113LL;

    long long getHash(string &s)
    {
        long long str_hash = 1;
        for( auto ch : s ){


            str_hash = BASE*str_hash + ((ch - s[0] + 26) % 26);
            //[az] => for z => 997 * (z-a+26)%26 = 997 * 25 = 997 ;
            //[ba] => for a => 997 * (a-b+26)%26 = 997 * 25 = 997 ;

            if(str_hash >= MOD) str_hash %= MOD;
        }

        return str_hash;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {

        unordered_map<long long, vector<string>> hashed_str;
        vector<vector<string>> grouped_str;

        int str_len = strings.size();

        for(auto &str : strings){

            hashed_str[getHash(str)].push_back(str);
        }

        for(auto &p : hashed_str)

        {
            grouped_str.push_back(p.second);
        }

        return grouped_str;

    }

    //hash function: f(x) = (ax+b)%c
            //x = string for hashing here
            //a = prime number 1
            //b = prime number 2
            //c = prime number 3
};
