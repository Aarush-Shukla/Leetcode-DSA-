//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> rowSum(n, 0);
        vector<int> colSum(n, 0);
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            int sum1 = 0, sum2 = 0;
            for(int j=0; j<n; j++){
                sum1 += matrix[i][j];
                sum2 += matrix[j][i];
            }
            rowSum[i] = sum1;
            colSum[i] = sum2;
            maxSum = max(maxSum, max(sum1, sum2));
        }
      
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int num = max(rowSum[i], colSum[j]);
                int diff = maxSum - num;
                cnt += diff;
                rowSum[i] += diff;
                colSum[j] += diff;
            }
        }
        return cnt;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends