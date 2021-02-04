class FenwickTree {
private:
    vector<int> sums;
    static inline int lowbit(int x) {return x & (-x);}
    
public:
    FenwickTree(int n) : sums(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums.size()) {
            sums[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int ret = 0;
        while (i > 0) {
            ret += sums[i];
            i -= lowbit(i);
        } 
        return ret;
    }
};

class NumArray {
private:
    FenwickTree tree;
    vector<int> nums_;
public:
    NumArray(vector<int>& nums) : tree(nums.size()), nums_(std::move(nums)) {
        for (int i = 0; i < nums_.size(); ++i) {
            tree.update(i + 1, nums_[i]);
        }
    }
    
    void update(int index, int val) {
        tree.update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return tree.query(right + 1) - tree.query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */