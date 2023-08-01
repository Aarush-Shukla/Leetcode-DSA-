//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
     bool isvalid (int x , int y , int n  , int m ){
    if(x<0 || y<0 || x>=n || y>=m )return false;
    return true;
}
  
  int solve (vector<vector<int>>grid, int destx, int desty ){
    
      //steps take to reach node 
      //visted array for each cell 
    
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>>vis(n, vector<int>(m,0));
      queue<vector<int>>q;
      vector<int>temp;
      temp.push_back(0);
      temp.push_back(0);
      temp.push_back(0);
      q.push(temp);
      
      vis[0][0]=1;
      
      while(!q.empty()){
          
          int steps = q.front()[0];
          int x = q.front()[1];
          int y = q.front()[2];
          q.pop();
          
          if(x==destx && y==desty){
              return steps;
          }
          
          int dx[] = {1,-1, 0, 0 };
          int dy[]= {0, 0 , 1, -1};
          
          for (int i=0; i<4; i++){
              
                   int newx = x +dx[i];
                   int newy = y+dy[i];
                   
                   if(isvalid(newx, newy,n, m) && grid[newx][newy]==1 && vis[newx][newy]==0){
                       vector<int>tt;
                       tt.push_back(steps+1);
                       tt.push_back(newx);
                       tt.push_back(newy);
                       q.push(tt);
                       vis[newx][newy]=1;
                   }       
          }
      }
      return -1;       
  }
   
  
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        return solve(A, X, Y);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends