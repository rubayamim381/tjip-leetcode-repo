//can be solved in brute force
//but this is i found optimal solution
//tc: O(n)+O(n)=O(n)
//mc: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1, len=nums.size();
        vector<int> final_prod;

        if(len<1) return final_prod;

        for(auto p:nums)
        {
            product *= p;
            final_prod.push_back(product);
        }

        product=1;
        for(int i=len-1; i>0; i--)
        {
            final_prod[i] = final_prod[i-1]*product;
            product *= nums[i];
        }

        final_prod[0]=product;

        return final_prod;
    }
};
