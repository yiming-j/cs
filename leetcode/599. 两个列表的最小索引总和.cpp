class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> idx1;
        for (int i = 0; i < list1.size(); ++i) {
            idx1[list1[i]] = i;
        }
        unordered_map<string, int> idxSum;
        vector<string> ret;
        for (int i = 0; i < list2.size(); ++i) {
            if (idx1.count(list2[i])) {
                int sum = idx1[list2[i]] + i;
                if (!ret.empty() && sum > idxSum[ret.back()]) {
                    continue;
                }
                if (!ret.empty() && sum < idxSum[ret.back()]) {
                    while (!ret.empty()) {
                        ret.pop_back();
                    }
                }
                ret.push_back(list2[i]);
                idxSum[list2[i]] = sum;
            }
        }
        return ret;
    }
};