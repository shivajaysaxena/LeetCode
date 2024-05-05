class Solution {
public:
    int strStr(string haystack, string needle) {
        int s=needle.length();
        for(int i=0;i<haystack.size();i++){
            if(needle == haystack.substr(i,s)){
                return i;
            }
        }
        return -1;
    }
};