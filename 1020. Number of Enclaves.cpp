class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j==0|| i==0 || i==r-1 || j==c-1){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1)
            count++;
        }
    }
    return count;
        
    }
    public:
    void dfs(vector<vector<int>>&arr,int i,int j){
        int r=arr.size();
        int c=arr[0].size();

        if(i<0 or j<0 or i>=r or j>=c or arr[i][j]==0)
        return;
        arr[i][j]=0;
        dfs(arr,i+1,j);
        dfs(arr,i-1,j);
        dfs(arr,i,j+1);
        dfs(arr,i,j-1);

    }
};
