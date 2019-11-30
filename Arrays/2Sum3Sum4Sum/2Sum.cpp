//O(n) time O(n) space
//x+y = t -> x = t-y
//since x = t-y and y = t-x no need to pre build has map
//inserting in the map each element if the complement is not in there is enough

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, size_t> num2idx;

    for (size_t i = 0; i < nums.size(); ++i) {

        if (num2idx.count(target-nums[i])) return {num2idx[target-nums[i]],i};            
        num2idx[nums[i]] = i;
    }

    return {};
}
