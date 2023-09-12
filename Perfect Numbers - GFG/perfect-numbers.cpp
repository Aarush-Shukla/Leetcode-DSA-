//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
       long long sum=1;
       if(N==1)
       return false;
       for(int i=2;i<=sqrt(N);i++){
           if(N%i==0){
               sum+=i;
               sum+=N/i;;
           }
       }
       if(sum==N)
       return true;
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends