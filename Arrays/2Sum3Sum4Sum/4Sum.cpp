void twoSum (vector<int> const& nums, int target, int d, int c, int left, vector<vector<int>>& ans) {

    int right = nums.size()-1;

    while (left < right) {

            int sum = nums[left] + nums[right]; 

            if (sum == target) {
                    ans.emplace_back(initializer_list<int>{d,c,nums[left++],nums[right]});
                    while (left < right && nums[left] == nums[left-1]) ++left;
            }
            else if (sum < target) ++left;
            else --right;
    }
}

void threeSum (vector<int> const& nums, int target, int d, int start, vector<vector<int>>& ans) {

    for (int i = start, iterations = nums.size()-2; i < iterations; ++i) {

    if (i > start && nums[i] == nums[i-1]) continue;
    twoSum(nums, target-nums[i], d, nums[i], i+1, ans);    
    }
}


vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> quadruplets;
    sort(nums.begin(), nums.end());

    for (int i = 0, iterations = nums.size()-3; i < iterations; ++i) {

        if (i > 0 && nums[i] == nums[i-1]) continue;
        threeSum(nums, target-nums[i], nums[i], i+1, quadruplets);   
    }

    return quadruplets;
}
