//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
     void dfs(int start, vector<int> adjList[], int visited[], vector<int> &ans) {
        visited[start] = 1; 
       // traverse all its neighbours
        for(auto it : adjList[start]) {
            // if the neighbour is not visited
            if(!visited[it]) {
                dfs(it, adjList, visited, ans); 
            }
        }
    }
    
    
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<int> adjList[V];
        
        //convert adjacency matrix to adjacency list
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                    
                }
            }
        }
        
        
        
        int visited[V] = {0}; 
        // create a list to store dfs
        vector<int> ans; 
        // call dfs for starting node
         int count =0;
        //for calling unconnected graph too
         for(int i=0;i<V;i++){
           if(!visited[i]){
               count++;
               dfs(i,adjList,visited,ans);
           }
       }
        return count; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends