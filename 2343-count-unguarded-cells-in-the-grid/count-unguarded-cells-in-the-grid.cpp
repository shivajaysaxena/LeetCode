class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<walls.size();i++){
            mat[walls[i][0]][walls[i][1]]=1;
        }
        
        for(int i=0;i<guards.size();i++){
            mat[guards[i][0]][guards[i][1]]=2;
        }
        
        for(int i=0;i<m;i++){
            bool guard=false;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    guard=false;
                }else if(mat[i][j]==0 and guard==true){
                    mat[i][j]=3;
                }else if(mat[i][j]==2){
                    guard=true;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            bool guard=false;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==1){
                    guard=false;
                }else if(mat[i][j]==0 and guard==true){
                    mat[i][j]=3;
                }else if(mat[i][j]==2){
                    guard=true;
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            bool guard=false;
            for(int j=0;j<m;j++){
                if(mat[j][i]==1){
                    guard=false;
                }else if(mat[j][i]==0 and guard==true){
                    mat[j][i]=3;
                }else if(mat[j][i]==2){
                    guard=true;
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            bool guard=false;
            for(int j=m-1;j>=0;j--){
                if(mat[j][i]==1){
                    guard=false;
                }else if(mat[j][i]==0 and guard==true){
                    mat[j][i]=3;
                }else if(mat[j][i]==2){
                    guard=true;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};