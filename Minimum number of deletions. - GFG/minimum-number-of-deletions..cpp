//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


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

int minDeletions(string str, int n) { 
     string B=string(str.rbegin(),str.rend());
       
       int p=str.length();
       int q=B.length();
       return n-lcs(p,q,str,B);
} 