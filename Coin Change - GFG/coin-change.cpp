//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    long long int count(int coins[],int N,int sum) {
        vector<vector<long long int>> dp (N+1,vector<long long int>(sum+1));
        for(long long int i=0;i<N+1;i++){
            dp[i][0] = 1;
        }
        for(long long int j=1;j<sum+1;j++){
            dp[0][j] = 0;
        }
        for(long long int i=1;i<N+1;i++){
            for(long long int j=1;j<sum+1;j++){
                if(coins[i-1]<=j){
                    long long int take = dp[i][j-coins[i-1]];
                    long long int not_take = dp[i-1][j];
                    dp[i][j] = take + not_take;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends