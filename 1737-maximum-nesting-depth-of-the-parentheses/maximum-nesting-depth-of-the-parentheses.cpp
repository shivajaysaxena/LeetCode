class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int cnt=0;
        int curr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                curr++;
            }
            else if(s[i]==')'){
                cnt=max(cnt,curr);
                curr--;
            }
            else{
                continue;
            }
        }
        return cnt;
    }
};