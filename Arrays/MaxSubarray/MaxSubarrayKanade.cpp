#include <vector>

//O(N) time, O(1) space
//max sum of a subarray in A[0,..,i] 
//maxSumA[0,..,i] = max(A[i], maxSumA[0,..,i-1])
int maxSubArray(vector<int>& nums) {       
        
  if (nums.empty()) return 0;
        
  int maxSum = nums[0];
  int currentMaxSum = nums[0];
        
  for (int i = 1; i < nums.size(); ++i) {            
    currentMaxSum = max(nums[i], nums[i]+currentMaxSum);
    maxSum = max(maxSum, currentMaxSum);
  }
        
  return maxSum;
}

