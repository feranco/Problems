#include <vector>
#include <limits>

//O(NlogN) time: every step split the input array in two parts
//and compute the maxSum including the median in linear time
//O(logN) space for the recursion stack
int maxSubArraySumAcrossM(vector<int> const& nums, int l, int m, int r) { 
        
    //in case of all negative values the result
    //from the across function shall be not considered
    int maxLeft = numeric_limits<int>::min();

    for (int i = m, sum = 0; i >= l; --i) {
        sum += nums[i];
        maxLeft = max(sum, maxLeft);
    }

    int maxRight = numeric_limits<int>::min();

    for (int i = m+1, sum = 0; i <= r; ++i) {
        sum += nums[i];
        maxRight = max(sum, maxRight);
    }

    return maxLeft + maxRight;
}

int maxSubArraySum(vector<int> const& nums, int l, int r) {       

    if (l == r) return nums[l];

    int m = (l+r) / 2;

    //max in the left subarray, the right subarray and the subarray across m
    vector<int> maximums {maxSubArraySum(nums, l, m), 
                          maxSubArraySum(nums, m+1, r), 
                          maxSubArraySumAcrossM(nums, l, m, r)};

    return *max_element(maximums.begin(), maximums.end());
}

int maxSubArray(vector<int>& nums) {       
    return maxSubArraySum(nums, 0, nums.size()-1);
}

