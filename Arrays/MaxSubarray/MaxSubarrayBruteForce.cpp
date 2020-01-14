#include <vector>
#include <limits>

//Brute Force is O(N^3)
int maxSubArray(vector<int>& nums) {

    int maxSum = numeric_limits<int>::min();

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            maxSum = max(maxSum, accumulate(begin(nums)+i, begin(nums)+j+1,0));
        }
    }
    return maxSum;
}


//O(N^2) with partial sum
int maxSubArray(vector<int>& nums) {

    int maxSum = numeric_limits<int>::min();

    for (int i = 0; i < nums.size(); ++i) {
        int pSum = 0;
        for (int j = i; j < nums.size(); ++j) {
            pSum += nums[j]; 
            maxSum = max(maxSum, pSum);
        }
    }
    return maxSum;
}
