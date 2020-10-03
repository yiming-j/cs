class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int result = 0;
        int s_size = staple.size(), d_size = drinks.size();
        int i = 0, j = d_size - 1;
        while (i < s_size && j >= 0) {
            while (j >= 0 && staple[i] + drinks[j] > x) {
                j--;
            }
            result += j + 1;
            result %= 1000000007;
            i++;
        }
        return result;
    }
};