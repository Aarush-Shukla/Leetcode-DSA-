//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
     //Function to find the nth catalan number.
    int mod = 1e9+7;
    int solve(int n,vector<long long int>& dp){
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        long long int ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans + solve(i,dp)*solve(n-i-1,dp))%mod;
        }
        return dp[n] = ans;
    }
    int solve_tab(int n){
        vector<long long int> dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            long long int ans = 0;
            for(int j=0;j<i;j++){
                ans = (ans + dp[j]*dp[i-j-1])%mod;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    int findCatalan(int n){
        // vector<long long int> dp(n+1,-1);
        // return solve(n,dp);
        return solve_tab(n);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends