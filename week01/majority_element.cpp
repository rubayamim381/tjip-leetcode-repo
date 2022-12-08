class Solution {
public:

    //TC: O(N)
    //SC: O(1)

    int majorityElement(vector<int>& nums) {

     int highest_freq=-1, vote=0, count=0, candidate, len=nums.size();

        //first iteration from where we get highest frequency candidate
        for(int i=0; i<len; i++)
        {
            if(vote==0)
            {
                highest_freq=nums[i];
                vote=1;
            }
            else
            {
                if(highest_freq==nums[i])
                    vote++;
                else
                    vote--;
            }
        }

    //second iteration from where we get highest frequency candidate
        for(int i=0; i<len; i++)
        {
            if(highest_freq==nums[i])
                count++;
        }

    //now, check the result
        if(count>len/2)
            return highest_freq;

        return -1;
    }
};
