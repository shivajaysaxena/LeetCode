class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> chains;
        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end(),
             [](const string& a, const string& b) {
                 return a.length() < b.length();
             });

        for (const string& word : sortedWords) {
            chains[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (chains.find(pred) != chains.end()) {
                    chains[word] = max(chains[word], chains[pred] + 1);
                }
            }
        }

        int maxChainLength = 0;
        for (const auto& entry : chains) {
            maxChainLength = max(maxChainLength, entry.second);
        }

        return maxChainLength;
    }
};