class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string x=to_string(n);
        sort(x.begin(),x.end());
        for(int i=0;i<31;i++){
            string pow=to_string(1<<i);
            sort(pow.begin(),pow.end());
            if(pow==x) return true;
        }
        return false;
    }
};