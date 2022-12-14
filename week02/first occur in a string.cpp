//approach 1: using substr() function
//tc: O(n-m), mc: O(1) where n = haystack length, m = needle length

class Solution {
public:
    int strStr(string haystack, string needle) {

        int withoutNeedle_Len = (int)(haystack.length()) - (int)(needle.length());

        for (int i = 0; i <= withoutNeedle_Len ; i++)
        {
            string sub_str = haystack.substr(i, needle.length());
            if ( sub_str == needle )
                return i;
        }
        return -1;
    }
};


//approach 2: using find() function to return the first index
//tc: O(n), mc: O(1)

class Solution {
public:
    int strStr(string& haystack, string& needle) {
        return haystack.find(needle);
    }
};
