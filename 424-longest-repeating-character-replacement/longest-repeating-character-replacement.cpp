class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;        
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxLen = 0;
        while(right < n) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            if(( (right-left+1) - maxFreq ) > k){
                freq[s[left] - 'A']--;
                maxFreq = 0;
                for(int i=0; i<26; i++){
                    maxFreq = max(maxFreq, freq[i]);
                }
                left++;
            }
            if( (right-left+1) - maxFreq  <=  k){
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};
