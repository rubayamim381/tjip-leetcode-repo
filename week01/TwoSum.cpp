class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> link;
        

        for(int i=0; i<nums.size(); i++)
            link.insert(pair<int, int>(nums[i], i));

        for(int index = 0; index < nums.size(); index++){
            int target_num=target-nums[index];
            if(link.find(target_num) != link.end() && link[target_num] != index)
                return { index, link[target_num] };

        }

        return {};
    }
};
