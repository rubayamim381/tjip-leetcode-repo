//tc = O(n), mc = O(1)
//n=number of elements

class Solution {
public:

    unordered_map<char, char> s_map, t_map;
    bool notIso = false;
    bool isIso = true;

    bool isIsomorphic(string s, string t) {

        int s_len = s.size(), t_len = t.size();

        if(s_len != t_len) return notIso;

        for(int i=0; i<s_len; i++)
        {
            if( s_map.count(s[i]) && s_map[s[i]] != t[i])
                return notIso;
            else
                s_map[s[i]] = t[i];

            if( t_map.count(t[i]) && t_map[t[i]] != s[i])
                return notIso;
            else
                t_map[t[i]] = s[i];
        }

        return isIso;

    }
};
