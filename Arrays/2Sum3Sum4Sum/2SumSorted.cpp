vector<int> twoSum(vector<int>& numbers, int target) {
        
    size_t i = 0, j = numbers.size()-1;

    while (i < j) {            
        int sum = numbers[i] + numbers[j];
        if (sum == target) return {i+1,j+1};
        else if (sum < target) i++;
        else j--;
    }
    return {};
}

// O(n) time O(1) space
// Two pointers p1 = 0, p2 = size-1
// p1+p2 = target ->return
// p1+p2 < target -> p1++
// p1+p2 > target -> p2--
