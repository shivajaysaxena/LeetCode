class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int targetIdx = 0;
        int targetLen = str2.length();
        for (char currChar : str1) {
            if (targetIdx < targetLen &&
                (str2[targetIdx] - currChar + 26) % 26 <= 1) {
                targetIdx++;
            }
        }
        return targetIdx == targetLen;
    }
};