class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> map;
        for (const auto num: arr1) {
            ++map[num];
        }
        vector<int> ans(arr1.size());
        int i = 0;
        for (const auto num : arr2) {
            for (int j = 0; j < map[num]; ++j) {
                ans[i++] = num;
            }
            map.erase(num);
        }
        for (const auto item: map) {
            for (int j = 0; j < item.second; ++j) {
                ans[i++] = item.first;
            }
        }
        return ans;
    }
};