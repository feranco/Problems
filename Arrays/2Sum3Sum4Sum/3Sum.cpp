void twoSum(vector<int> const& nums, int left, int target, vector<vector<int>>& ans) {
        
    int right = nums.size()-1;

    while (left < right) {            
        int sum = nums[left] + nums[right];
        if (sum == target) {
            ans.emplace_back(initializer_list({-target, nums[left++], nums[right--]}));
            while (left < right && nums[left-1] == nums[left]) ++left; //skip duplicates
            while (left < right && nums[right+1] == nums[right]) --right; //skip duplicates
        }
        else if (sum < target) ++left;
        else --right;  
    }
}


vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    vector<vector<int>> triplets;

    for (int i=0, iterations = (nums.size()-2); i<iterations; ++i) {
        //skip duplicates
        if(i == 0 || nums[i] != nums[i-1])
            twoSum(nums, i+1, -nums[i], triplets); //a+b+c=0 -> a+b=-c; nums[i] = c
    }

    return triplets;
}
