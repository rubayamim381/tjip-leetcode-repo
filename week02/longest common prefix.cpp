//TC: O(n*200), MC: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int len = strs.size();
        int commonPrefix_len = 200;
        string word, prefixStr;

        //this word would be matched with others
        string sampleWord = strs[0];

        //extract strings to word
        for(int i=1; i<len; i++)
        {
            //["flower","flow","flight"] = ["flow"], ["flight"]
            word = strs[i];
            int word_len = strs[i].size(), prefix_len = 0;

            //["flow"] = ['f','l','o','w']
            //["flight"] = ['f','l','i','g','h','t']
            for(int j=0; j<word_len; j++)
            {
                //count "flower" and "flow" prefix length
                if(word[j] == sampleWord[j])
                    prefix_len++;
                else break;
            }

            //find the least common prefix length among strings
            commonPrefix_len = min(commonPrefix_len, prefix_len);
        }

        if( len == 1 )
            return sampleWord;

        for( int i=0; i<commonPrefix_len; i++)
            prefixStr.push_back( sampleWord[i] );

        return prefixStr;
    }
};
