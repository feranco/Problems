class TwoSum {
    unordered_map<int, int> num2freq;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        num2freq[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto data : num2freq) {
            int num = data.first, freq = data.second, comp = value-num;
            if (num2freq.count(comp) && (comp != num || (freq > 1))) return true;    
        }
        return false;
    }
};

//O(1) add, O(n) find, O(n) space
//if the complementary value exists in the map and it is equal to the current number
//the frequency of the current number shall be > 1
