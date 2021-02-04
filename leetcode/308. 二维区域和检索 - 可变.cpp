class FenwickTree {
private:
    vector<vector<int>> sums;
    static inline int lowbit(int x) {return x & (-x); }
public:
    FenwickTree() {}
    FenwickTree(int m, int n) : sums(m + 1, vector<int>(n + 1)) {}
    
    void update(int row, int col, int delta) {
        for (int i = row; i < sums.size(); i += lowbit(i)) {
            for (int j = col; j < sums[0].size(); j += lowbit(j)) {
                sums[i][j] += delta;
            }
        }
    }
    
    int query(int row, int col) {
        int ret = 0;
        for (int i = row; i > 0; i -= lowbit(i)) {
            for (int j = col; j > 0; j -= lowbit(j)) {
                ret += sums[i][j];
            }
        }
        return ret;
    }
};

class NumMatrix {
private:
    vector<vector<int>> matrix_;
    FenwickTree tree;
public:
    NumMatrix(vector<vector<int>>& matrix) : matrix_(std::move(matrix)) {
        if (matrix_.size() == 0 || matrix_[0].size() == 0) {
            return;
        }
        tree = FenwickTree(matrix_.size(), matrix_[0].size());
        for (int i = 0; i < matrix_.size(); ++i) {
            for (int j = 0; j < matrix_[0].size(); ++j) {
                tree.update(i + 1, j + 1, matrix_[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        tree.update(row + 1, col + 1, val - matrix_[row][col]);
        matrix_[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return tree.query(row2 + 1, col2 + 1) - tree.query(row1, col2 + 1) - tree.query(row2 + 1, col1) + tree.query(row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

