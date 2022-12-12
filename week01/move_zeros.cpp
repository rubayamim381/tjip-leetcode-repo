//TC: O(n), MC:O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size(), j=0;

        for(int i=0; i<len; i++)
        {
            if(nums[i]!=0) {
                nums[j]=nums[i];
                j++;
            }
        }

        for(int i=j;i<len;i++){
            nums[i]=0;
        }
    }
};
