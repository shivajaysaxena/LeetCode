class Solution {
public:
    bool isvlv(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int cnt=0;
        for(char ch:s){
            if(isvlv(ch)) cnt++;
        }
        if(!cnt) return false;
        return true;
    }
};