// C++ solution
class Solution {
public:
    vector<vector<int>> dir = {{0 , 1} ,{1 , 0} ,{1 , 1} , {1 , -1} , {-1 , 1} , {-1 , 0} , {0,-1 },{-1 , -1} };
    int n , m;
    bool isValid(int i , int j , vector<vector<int>> &grid){
        if(i<0 or j<0 or i>=n or j>=m) return false;
        if(grid[i][j]==1) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]==1) return -1;

        queue<vector<int>> q;
        q.push({0, 0 , 0});
        grid[0][0] = 1;

        while(!q.empty()){
            int p = q.size();
            for(int i=0 ; i<p ; i++ ){
                auto node = q.front();
                q.pop();
                int x = node[0];
                int y = node[1];
                grid[x][y] = 1;
                int steps = node[2];
                if(x==n-1 and y==m-1) return steps+1;
                for(int k= 0; k<8  ; k++){
                    int dx = dir[k][0];
                    int dy = dir[k][1];
                    int newx = x + dx;
                    int newy = y + dy;
                    if(isValid(newx , newy , grid)){
                        grid[newx][newy] = 1;
                        q.push({newx , newy , steps+1});
                    }
                }
            }

        }

        return -1;
    }
};