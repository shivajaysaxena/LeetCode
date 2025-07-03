class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        int n = 1;
        while(n<k){
            n = word.size();
            for(int i = 0; i < n; i++){
                if(word[i] == 'z'){
                    word.push_back('a');
                }
                else{
                    word.push_back(word[i]+1);
                }
            }
        }
        return word[k-1];
    }
};