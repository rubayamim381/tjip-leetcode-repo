class Solution {
    //i can solve it using priority queue
    //where tc: o(n)+klogn
    //but the best approach is quickSelect. I will use it here
public:

    int quickSelect(vector<int>& nums, int left, int right)
    {
        int pivot=nums[right], pointer=left;

        for(int i=left; i<right; i++)
        {
            if(nums[i]<=pivot)
            {
                swap(nums[pointer],nums[i]);
                pointer++;
            }
        }

        swap(nums[pointer], nums[right]);

        return pointer;

    }

    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        int low=0, high=nums.size()-1;

        while(low<high)
        {
            int pointer = quickSelect(nums, low, high);
            if(pointer==k) break;
            if(pointer < k) low=pointer+1;
            else high=pointer-1;
        }
        return nums[k];
    }
};
