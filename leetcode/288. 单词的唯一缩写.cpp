class ValidWordAbbr {
private:
    unordered_map<string, vector<string>> map;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const auto &word : dictionary) {
            if (word.size() <= 2) {
                map[word].push_back(word);
            } else {
                string encode = word.front() + to_string(word.size() - 2) + word.back();
                map[encode].push_back(word);
            }
        }
    }
    
    bool isUnique(string word) {
        if (word.size() <= 2) {
            return true;
        } 
        string temp = word.front() + to_string(word.size() - 2) + word.back();
        for (const auto &w : map[temp]) {
            if (w != word) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */