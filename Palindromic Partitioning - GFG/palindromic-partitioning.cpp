//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
int dp[500][500];
    public:
    bool pal(string &s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return 0;
        }
        return 1;
    }
public:
    int fun(string &s,int i,int j){
        if(i>= j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(pal(s,i,j)) return dp[i][j]= 0;
        int ans = j-i+1;
        for(int k= i; k<j; k++){
            if(dp[i][k] != -1)
            ans = min(ans, 1+dp[i][k] + fun(s,k+1,j));
            else if(dp[k+1][j]!= -1){
                 ans = min(ans, 1+dp[k+1][j] + fun(s,i,k));
            }
            else if(dp[i][k] != -1 && dp[k+1][j] != -1)
            {
                ans = min(ans, 1+dp[k+1][j] + dp[i][k]);
            }
            else{
                ans = min(ans, 1+fun(s,k+1,j) + fun(s,i,k));
            }
        }
        return dp[i][j] = ans;
    }
public:
    int palindromicPartition(string &s)
    {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return fun(s,0,n-1);
         
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends