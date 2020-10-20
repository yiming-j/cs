class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int size_name = name.size();
        int size_typed = typed.size();
        int i = 0, j = 0;
        while (j < size_typed) {
            if (i < size_name && name[i] == typed[j]) {
                ++i;
                ++j;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                ++j;
            } else {
                return false;
            }
        }
        return i == size_name;
    }
};