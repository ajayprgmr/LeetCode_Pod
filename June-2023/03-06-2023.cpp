// C++ Solution
class Solution 
{
public:
    vector<vector<int>> adjList;
    int maxTimeNeeded = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        initialize(manager,n);
        dfs(headID,0,informTime);
        return maxTimeNeeded;
    }

    void initialize(vector<int>& manager,int n) 
    {
        adjList.resize(n);
        int employeeIndex = 0;
        for (int managerIndex : manager) 
        {
            if (managerIndex != -1) 
            {
                adjList[managerIndex].push_back(employeeIndex);
            }
            employeeIndex++;
        }
    }

    void dfs(int currentNode, int currentTime, vector<int>& informTime) 
    {
        if (currentTime > maxTimeNeeded) 
        {
            maxTimeNeeded = currentTime; 
        }
        
        for (int subordinate : adjList[currentNode]) 
        {
            int updatedTime = currentTime + informTime[currentNode];
            dfs(subordinate, updatedTime, informTime);
        }
    }


};