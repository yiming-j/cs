class Solution {
private:
    vector<int> arr;
    vector<int> origin;
    
public:
    Solution(vector<int>& nums) {
        origin = nums;
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = origin;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = arr.size() - 1; i >= 0; --i) {
            swap(arr[i], arr[rand() % (i + 1)]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */