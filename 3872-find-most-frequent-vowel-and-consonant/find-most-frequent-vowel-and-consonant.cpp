#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isvlv(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> vmap, cmap;
        int maxvlv = 0, maxcons = 0;

        for(char ch : s){
            if(isvlv(ch)){
                vmap[ch]++;
                maxvlv = max(maxvlv, vmap[ch]);
            } else {
                cmap[ch]++;
                maxcons = max(maxcons, cmap[ch]);
            }
        }

        return maxvlv + maxcons;
    }
};
