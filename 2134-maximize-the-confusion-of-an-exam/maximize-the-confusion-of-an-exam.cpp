class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int extra=0,mx=0;
        int i=0,j=0;
        while(j<s.size()){ //For consecutive TRUE
            if(s[j]=='F'){
                extra++;
                while(extra>k){
                    if(s[i]=='F')extra--;
                    i++;
                }
            }
            mx = max(mx,j-i+1);
            j++;
        }
        i=0;j=0;
        extra=0;
        while(j<s.size()){ //For consecutive FALSE
            if(s[j]=='T'){
                extra++;
                while(extra>k){
                    if(s[i]=='T')extra--;
                    i++;
                }
            }
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};