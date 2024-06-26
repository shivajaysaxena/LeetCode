class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i;
        for(i=0;i<min(word1.size(),word2.size());i++){
            ans = ans + word1[i];
            ans = ans + word2[i];
        }
        if(i != word1.size()){
            while(i != word1.size()){
                ans = ans + word1[i];
                i++;
            }
        }
        else if(i != word2.size()){
            while(i != word2.size()){
                ans = ans + word2[i];
                i++;
            }
        }
        return ans;
    }
};