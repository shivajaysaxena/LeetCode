class TreeAncestor {
public:
vector<vector<int>> ancestors;
int max_level; 
    TreeAncestor(int n, vector<int>& parent) {
        max_level=0;
        int temp_n=n;
        while(temp_n>0){
            max_level++;
            temp_n>>=1;
        }
        ancestors.resize(n,vector<int>(max_level,-1));
        for(int i=0;i<n;i++){
            ancestors[i][0]=parent[i];
        }
        for(int j=1;j<max_level;j++){
            for(int i=0;i<n;i++){
                int parent_node=ancestors[i][j-1];
                if(parent_node!=-1){
                    ancestors[i][j]=ancestors[parent_node][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<max_level;i++){
            if((k>>i) & 1){
                node=ancestors[node][i];
                if(node==-1){
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */