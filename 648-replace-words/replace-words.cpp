class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        set<string> st;
        for(auto &w : dictionary) st.insert(w);

        string ans =  "";
        int n = s.length();
        for(int i=0; i<n;){
            string word = "";
            while(i < n && s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }
            string prefix = "";
            bool replaceFound = false;
            for(auto &c : word){
                prefix.push_back(c);


                if(st.count(prefix)){
                    replaceFound = true;
                    break;
                }
            }            

            ans += replaceFound ? prefix : word;
            if(i < n) ans.push_back(' ');

            i++;
        }

        return ans;
    }
};