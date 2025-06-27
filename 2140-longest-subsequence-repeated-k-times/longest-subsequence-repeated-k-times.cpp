class Solution {
public:
    int f(string& str, int k, string& s) {
        int count = 0;
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = str.size();
        while (i < n) {
            if (s[i] == str[j]) {
                j++;
                if (j == m) {
                    count++;
                    j = 0;
                }
            }
            i++;
        }
        return count >= k;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (auto it : s)
            freq[it - 'a']++;
        queue<string> q;
        vector<char> rep;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                rep.push_back(i + 'a');
                q.push(string(1, i + 'a'));
            }
        }
        string ans;
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size())
                ans = curr;
            for (auto it : rep) {
                string str = curr + it;
                if (f(str, k, s)) {
                    q.push(str);
                }
            }
        }
        return ans;
    }
};