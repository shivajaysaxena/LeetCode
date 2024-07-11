class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        int start, bsStart = 0;
        string curr;
        for (char& c : searchWord) {
            curr += c;
            start =
                lower_bound(products.begin() + bsStart, products.end(), curr) -
                products.begin();
            result.push_back({});
            for (int i = start; i < min(start + 3, (int)products.size()) &&
                                !products[i].compare(0, curr.size(), curr);
                 i++)
                result.back().push_back(products[i]);
            bsStart = start;
        }
        return result;
    }
};