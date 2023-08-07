//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

int lcs(int n, int m, string s1, string s2){
    n=s1.length();
    m=s2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1));
 
    //Base Case

for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){

        dp[i][0]=0;
        dp[0][j]=0;

    }
}

//Choice Diagram

for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){

        if(s1[i-1]==s2[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
        }
         else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
    
      return dp[n][m];

}

    int findMinInsertions(string S){
     string B=string(S.rbegin(),S.rend());
       
       int p=S.length();
       int q=B.length();
       return p-lcs(p,q,S,B);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends