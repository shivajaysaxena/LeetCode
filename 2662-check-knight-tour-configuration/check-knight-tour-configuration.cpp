class Solution {
public:
    bool isvalid(int row,int col,int prevrow,int prevcol){
        if(abs(prevcol-col)==2&& abs(prevrow-row)==1) return true;
         if(abs(prevcol-col)==1&& abs(prevrow-row)==2) return true;
        return false;
    }
     bool valid(vector<vector<int>>& grid,int n,int row,int col,int num){
        int newrow=-1;
        int newcol=-1;
        if(num==(n*n-1)) return true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==num+1){
                    newrow=i;
                    newcol=j;
                    
                }
            }
        }
        if(isvalid(newrow,newcol,row,col)){
            if(valid(grid,n,newrow,newcol,num+1)) return true;
        }
        return false;

     }

    bool checkValidGrid(vector<vector<int>>& grid) {
         if(grid[0][0]!=0) return false;
       return valid(grid,grid.size(),0,0,0);
    }
};