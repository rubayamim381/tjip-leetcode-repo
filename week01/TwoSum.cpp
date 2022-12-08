class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> link;

        for(int i=0; i<nums.size(); i++)
            link.insert(pair<int, int>(nums[i], i));

        for(int index = 0; index < nums.size(); index++){

            if(link.find(target-nums[index]) != link.end() && link[target-nums[index]] != index)
                return {index, link[target-nums[index]]};

        }

        return {};
    }
};
