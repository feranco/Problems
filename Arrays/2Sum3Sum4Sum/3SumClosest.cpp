int twoSumClosest(vector<int>& nums, int target, int left) {
       
        int right = nums.size()-1;
		int offset = numeric_limits<int>::max(), closestSum = 0;
        cout << target << " ";
        while (left < right) {
            int sum = nums[left] + nums[right];
			int currentOffset = abs(sum - target);
            if (currentOffset == 0) return sum;
            else if (currentOffset < offset){
			   closestSum = sum;
			   offset = currentOffset; 
            }
			(sum < target) ? ++left : --right;
        }
		
		return closestSum;
    }
   
public:
int threeSumClosest(vector<int>& nums, int target) {

    sort(nums.begin(), nums.end());

    int offset = numeric_limits<int>::max();
    int closestSum = -1;

    for (int i = 0, iterations = nums.size()-2; i < iterations; ++i) {
        int currentClosestSum = twoSumClosest(nums, target-nums[i], i+1) + nums[i]; //a+b+c
        cout << currentClosestSum << endl;
        int currentOffset = abs(currentClosestSum-target);
                    if (currentOffset < offset) {
            offset = currentOffset;
            closestSum = currentClosestSum;
        }
    }
    return closestSum;
}

//O(N^2) time, O(1) space
