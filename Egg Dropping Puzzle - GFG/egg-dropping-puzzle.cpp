//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
   
   int eggDropMemoOptmized(int n, int k, vector<vector<int>> &dp){
         if(k == 0 || k == 1)
            return k;
        if(n == 1)
            return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mn = INT_MAX, x;
        
        for(x = 1; x <= k; x++){
            
            int low, high = 0;
            
            if(dp[n-1][x-1] != -1)
                low = dp[n-1][x-1];
            else
                low = eggDropMemoOptmized(n-1, x-1, dp);
                
            if(dp[n][k-x] != -1)
                high = dp[n][k-x];
            else
                high = eggDropMemoOptmized(n, k-x, dp);
                
            int temp = 1+max(low, high);
            
            mn = min(mn, temp);
        }
        
        return dp[n][k] = mn;
    }
   
   
    int eggDrop(int n, int k){
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return eggDropMemoOptmized(n, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends