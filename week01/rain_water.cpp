class Solution {
public:
    //TC: O(n)
    //MC: O(1)
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1, total_gain=0, left_max=0, right_max=0;

        while(left<right)
        {
            if(height[left]<height[right])
            {
                //left_max = the last left max height
                left_max=max(left_max, height[left]);
                total_gain += left_max-height[left];
                left++;
            }
            else{
                //right_max = the last right max height
                right_max=max(right_max, height[right]);
                total_gain += right_max-height[right];
                right--;
            }
        }

        return total_gain;
    }
};
