class Solution {
public:
	//Depth First Seach function
    void dfs(int node,vector<vector<pair<int,int>>>&graph,vector<int>&vis,vector<int>&ans){
	//mark the node in the visited vector
        vis[node]=0;
		//traverse through all the neighbouring nodes
        for(auto&child:graph[node]){
		//if they are not visited yet
            if(vis[child.first]){
			//push node in ans vector;
                ans.push_back(child.first);
				//dfs call for neighbours
                dfs(child.first,graph,vis,ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
	
        vector<vector<pair<int,int>>>graph(n);
		//First we will create a graph with the given edges and weights
		//by making graph a vector of vector of pair
		
        for(auto&road:roads){
            
            graph[road[0]-1].push_back({road[1]-1,road[2]});
            graph[road[1]-1].push_back({road[0]-1,road[2]});
        }
		//for the dfs we require a visited array so we created a vis vector
        vector<int>vis(n,1);
		//we will store the visited nodes in ans vector;
        vector<int>ans;
		
		//we will call the dfs to find the visited nodes from node 0
        dfs(0,graph,vis,ans);
		
		//now we will find the minimum possible edge possible on the visited 
		//as we must have to include the  minimun weight edge
        int res=1e9;
        for(int i=0;i<ans.size();i++){
		//Traversing through all the edges of node
            for(auto&child:graph[ans[i]]){
			//storing min in res
                res=min(res,child.second);
            }
        }
		//returning the res
        return res;
    }
};
