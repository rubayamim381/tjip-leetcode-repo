class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int single_num=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            single_num = single_num ^ nums[i];
        }

        return single_num;
    }
};
