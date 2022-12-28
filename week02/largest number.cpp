// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        //sorted according to each character's Unicode code point value
        //a=The first element for comparison.
        //b=The second element for comparison.

        sort(nums.begin(),nums.end(),[&](const int& a,const int& b){

            string s1 = to_string(a) + to_string(b);
            string s2 = to_string(b) + to_string(a);
            return s1 > s2;
        });

        //[3,30,34,5,9]
        //after sorting nums = [9, 5, 34, 3, 30]

        string largestNumber = "";

        for(auto& ch : nums){
            largestNumber += to_string(ch);
        }
        return largestNumber[0] == '0' ? "0" : largestNumber;
    }
};
