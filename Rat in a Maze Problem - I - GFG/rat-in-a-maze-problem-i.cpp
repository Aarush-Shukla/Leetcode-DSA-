//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
bool isSafe(vector<vector<int>>& m,int n,int x,int y,vector<vector<int>> visited,string output,vector<string>& ans){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (m[x][y]==1)){
        return true;
    }else{
        return false;
    }
}

void solve(vector<vector<int>>& m,int n,int x,int y,vector<vector<int>> visited,string output,vector<string>& ans){
    //Base Case
    if(x==n-1 && y==n-1){
        ans.push_back(output);
        return;
    }
    visited[x][y]=1;
    //choices- D,L,U,R
    
    //Down
    int newx=x+1;
    int newy=y;
    if(isSafe(m,n,newx,newy,visited,output,ans)){
        output.push_back('D');
        solve(m,n,newx,newy,visited,output,ans);
        output.pop_back();
    }
    //Left
    newx=x;
    newy=y-1;
    if(isSafe(m,n,newx,newy,visited,output,ans)){
        output.push_back('L');
        solve(m,n,newx,newy,visited,output,ans);
        output.pop_back();
    }
    
    //Up
    newx=x-1;
    newy=y;
    if(isSafe(m,n,newx,newy,visited,output,ans)){
        output.push_back('U');
        solve(m,n,newx,newy,visited,output,ans);
        output.pop_back();
    }
    
    //Right
    newx=x;
    newy=y+1;
    if(isSafe(m,n,newx,newy,visited,output,ans)){
        output.push_back('R');
        solve(m,n,newx,newy,visited,output,ans);
        output.pop_back();
    }
    
    
    visited[x][y]=0;
}


class Solution{
    public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        string output="";
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        int srcx=0;
        int srcy=0;
        solve(m,n,srcx,srcy,visited,output,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends