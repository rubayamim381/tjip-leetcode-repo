// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//Approach: Binary search
//TC: O(logn), MC: O(1)

class Solution {
public:
    int firstBadVersion(int n) {

        int low=0, high=n;

        while(low != high-1)
        {
            int check = low + (high - low) / 2;

            if(!isBadVersion(check))
                low = check;
            else
                high = check;
        }

        return high;
    }
};
