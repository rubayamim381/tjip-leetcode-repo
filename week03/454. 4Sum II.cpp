// tc: O(n^2), mc: O(n)
//n = number of values
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int, int> pairwise_sum;
        int tuple_cnt = 0;

        for(auto &p : nums1)
        {
            for(auto &q : nums2)
            {
                pairwise_sum[p+q]++;
            }
        }

        for(auto &p : nums3)
        {
            for(auto &q : nums4)
            {
                if( pairwise_sum.count(-(p+q)) ){
                    tuple_cnt += pairwise_sum[-(p+q)];
                }
            }
        }

        return tuple_cnt;
    }

    //for example: nums1[1,2], nums2[-2,-1]
    //pairwise summation: nums1[0] + nums2[0] = -1
    //                    nums1[0] + nums2[1] = 0
    //                    nums1[1] + nums2[0] = 0
    //                    nums1[1] + nums2[1] = -1
    //in unordered map, values are: -1 -> 1, 0 -> 2, 1 -> 1

    //Traverse in nums3[n] and nums4[n] and search (-(nums3[j]+nums[k])) from pairwise summation
    //to get the final result where 0<=j,k<=n

    //for example: nums3[-1,2], nums4[0,2]
    // -( nums3[0] + nums4[0] ) = -(-1) = 1 . Find in map 1->1. total = 1
    // -( nums3[0] + nums4[1] ) = -(1) = -1 . Find in map -1->1. total = 1+1 =2
    // -( nums3[1] + nums4[0] ) = -(2) = -2 . cannot find in map
    // -( nums3[1] + nums4[1] ) = -(4) = -4 . cannot find in map

};
