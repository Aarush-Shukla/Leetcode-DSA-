//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
bool isSafe(vector<vector<int>>& m,int n,int row,int col,vector<vector<int>> visited,string output,vector<string>& ans){
    if((row>=0 && row<n) && (col>=0 && col<n) && (visited[row][col]==0) && (m[row][col]==1)){
        return true;
    }else{
        return false;
    }
}

void solve(vector<vector<int>>& m,int n,int row,int col,vector<vector<int>> visited,string output,vector<string>& ans){
    //Base Case
    if(row==n-1 && col==n-1){
        ans.push_back(output);
        return;
    }
    visited[row][col]=1;
    //choices- D,L,U,R
    
    //Down
    int newrow=row+1;
    int newcol=col;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('D');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    //Left
    newrow=row;
    newcol=col-1;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('L');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    
    //Up
    newrow=row-1;
    newcol=col;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('U');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    
    //Right
    newrow=row;
    newcol=col+1;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('R');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    
    
    visited[row][col]=0;
}
    
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
        int srcrow=0;
        int srccol=0;
        solve(m,n,srcrow,srccol,visited,output,ans);
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