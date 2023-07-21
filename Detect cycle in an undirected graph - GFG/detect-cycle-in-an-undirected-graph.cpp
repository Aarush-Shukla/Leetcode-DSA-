//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    // bool isCycle(int src,int V, vector<int> adj[],int vis[]){
    //     queue <pair<int,int>> q;
    //     vis[src]=1;
    //     q.push({src,-1});
    //     while(!q.empty()){
    //         int node=q.front().first;
    //         int parent=q.front().second;
    //         q.pop();
            
    //         for(auto i:adj[node]){
    //             if(!vis[i]){
    //                 vis[i]=1;
    //                 q.push({i,node});
    //             }else if(i!=parent){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    
    
    bool isCycle_DFS(int node,int parent,int vis[],vector<int> adj[] ){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(isCycle_DFS(i,node,vis,adj)){
                    return true;
                }
            }
            else if(i!=parent) { // iss condition mai viited hai i aur vo parent nahi hai iska matlab cycle hai
                return true;
            }
        }
        return false;
    }
    
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // int vis[V]={0};
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         if(isCycle(i,V,adj,vis)){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        
        
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(isCycle_DFS(i,-1,vis,adj)){
                return true;
            }
        }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends