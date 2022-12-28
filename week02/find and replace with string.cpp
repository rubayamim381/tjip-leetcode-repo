// TC:  O(n + m), m is the number of targets, MC: O(n)

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {

        int S_len = S.length();
        int index_len = indexes.size();
        string ReplaceString;

        vector< pair<int, string> > bucket(S_len);

        //S = "abcd"
        //indices = [0, 2]
        //sources = ["ab","ec"],
        //targets = ["eee","ffff"]
        for (int i = 0; i < index_len; ++i)
        {
            if (S.compare(indexes[i], sources[i].length(), sources[i]) == 0)
            {
                bucket[indexes[i]] = {sources[i].length(), targets[i]};
            }
            //bucket -> [sources_len=2, targets="eee"]
        }

        for (int i = 0; i < S.length();)
        {
            //replace with first substring
            if (bucket[i].first) {
                ReplaceString += bucket[i].second;
                i = (i + bucket[i].first);
            }

            //if there is any string left without sources, push back to ReplaceString
            else {
                ReplaceString.push_back(S[i++]);
            }
        }

        return ReplaceString;
    }
};
