//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
  bool subsetSum(int arr[],int n,int range, vector<vector<int>> &dp){
      
     for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<range+1;j++){
            dp[0][j] = 0;
        }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<range+1;j++){
            
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            
                
            }
            else if(arr[i-1]<=j){
                
                int take=dp[i-1][j-arr[i-1]];
                int not_take=dp[i-1][j];
                dp[i][j]= take || not_take;
                
            }
        }
    }  
    
    return dp[n][range];
}
  
  
	int minDifference(int arr[], int n)  { 
	    int range=0;
	    for(int i=0;i<n;i++){
	        range+=arr[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(range+1,-1));
	   
	   subsetSum(arr,n,range,dp);
	   
	    vector<int> subset1(range/2+1);
	    
	    for(int i=0;i<range/2+1;i++ ){
	       if(dp[n][i]){
	           subset1.push_back(i);
	       }
	    }
	    
	    int mini=INT_MAX;
	    for(int i=0;i<subset1.size();i++){
	        mini=min(mini,range-2*subset1[i]);
	    }
	
	return mini;
	    
	} 
	
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends