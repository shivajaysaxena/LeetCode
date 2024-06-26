class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int types_num = set<int>(candies.begin(), candies.end()).size();
        if (types_num > candies.size() / 2) {
            return candies.size() / 2;
        }
        return types_num;
    }
};