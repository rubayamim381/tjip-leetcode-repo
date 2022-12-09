class Solution {
public:
// TC: O(N)
// MC: O(1)
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int nums_len=nums.size();
        int longest_len=0;
        int max_len=1;

        for(int i=0; i<nums_len-1; i++)
        {
            //counting max length
            if(nums[i+1]-nums[i]==1)
            {
                max_len++;
            }

            //breakpoint
            if(nums[i+1]-nums[i]>1)
            {
                longest_len=max(longest_len, max_len);
                max_len=1;
            }

            //final count for last index
            if(i+1==nums_len-1)
                longest_len=max(longest_len, max_len);

        }

        if(nums_len==1) longest_len=1;

        return longest_len;
    }
};
