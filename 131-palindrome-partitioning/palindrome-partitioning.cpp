class Solution {
public:
  bool ispalindrome(string s1,int s,int e){
       if(s1.length()==1){
           return true;
       }
        
       while(s<=e){
           if(s1[s]!=s1[e]){
               return false;
               break;
           }
           else{
               s++;
               e--;
           }
       }
       return true;
  }
 void solve(int ind,string s ,vector<string>&temp,vector<vector<string>>&ans){
        if(ind==s.size()){
             ans.push_back(temp);
             return ;
        }
        for(int i =ind;i<s.size();++i){
            if(ispalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
  }
   
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,temp,ans);
        return ans;

    }
};