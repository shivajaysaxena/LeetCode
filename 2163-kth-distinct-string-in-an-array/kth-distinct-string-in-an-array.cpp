class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for (auto& word : arr)
            map[word]++;
        for (auto& word : arr)
            if (map[word] == 1 && --k == 0)
                return word;
        return "";
    }
};