    //i can solve it using priority queue
    //where tc: o(n)+klogn
    //but the best approach is quickSelect. I will use it here
    //tc: o(n) for best case, o(n^2) for worst case

class Solution {
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


    //i can solve it using priority queue
    //where tc: o(n)+klogn
    //but the best approach is minHeap solution in priority queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> priority_q;

        for(auto p:nums)
        {
            priority_q.push(p);
            if(priority_q.size() > k)
                priority_q.pop();

        }
        return priority_q.top();
    }
};
