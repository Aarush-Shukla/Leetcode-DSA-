//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int matrixMultiplication(int N, int arr[])
    {
            vector<vector<int>>dp(N+1,vector<int>(N+1,0));
        for(int i = 1 ; i< N ; i++){
            dp[i][i]=0;
        }
        for(int i = N-1 ; i>=1 ; i--){
            for(int j = i+1 ; j<=N-1;j++ ){
                int mini = 1e9;
                for(int k=i ; k<=j-1 ; k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(steps, mini);
                }
                 dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code EndsMatrix Chain Multiplication
