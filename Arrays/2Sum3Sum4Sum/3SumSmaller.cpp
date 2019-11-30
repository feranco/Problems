int twoSumSmaller(vector<int> const& nums, int target, int left) {
        
    int nCouples = 0, right = nums.size()-1;

    //no couple starting in nums[left] can have sum less then target
    while (left < right) { 
        int sum = nums[left] + nums[right];   
        if (sum < target) {
            //all couples nums[left], nums[i] with i <= right
            //have sum less than target
            nCouples += right-left;
            ++left;
        }
        else {
            //no couple ending in nums[right] can have sum less then target
            --right;
        }
    }
    return nCouples;
}


int threeSumSmaller(vector<int>& nums, int target) {

    sort(nums.begin(), nums.end());
    int nTriplets = 0;

    for (int i = 0, iterations = nums.size()-2; i < iterations; ++i) {       
        nTriplets += twoSumSmaller(nums, target-nums[i], i+1);
    }
    return nTriplets;
}


//a+b+c < t -> a+b < t-c -> check (t-c) - (a+b) > 0, if true nTriplets++;
//(O(n^2)) time, O(1) space
//because of negative numbers the condition while (left < right && nums[left] <= target) 
//cannot be applied to short the number of iterations [-4,-4,-3,-2,-1,0,2]
