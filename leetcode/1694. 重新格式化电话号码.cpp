class Solution {
public:
    string reformatNumber(string number) {
        string ret;
        int count = 0;
        for (int i = 0; i < number.size(); ++i) {
            if (!isdigit(number[i])) {
                continue;
            }
            ret += number[i];
            ++count;
            if (count == 3) {
                ret += '-';
                count = 0;
            }
        }
        if (ret.size() == 1) {
            return ret;
        }
        if (count == 0) {
            ret.pop_back();
        } else if (count == 1) {
            ret.erase(ret.size() - 2, 1);
            ret.insert(ret.size() - 2, "-");
        }
        return ret;
    }
};