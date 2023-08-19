//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int i=0;
        int j=0;
        long long sum=0;
        vector<int> ans;
        
        if(s==0){
            ans.push_back(-1);
            return ans;
        }
        
            while(j<n){
            
            sum+=arr[j];
            
            while(sum>s){  // if sum is more then we slide the window 
                sum-=arr[i];
                i++;
            }
            
            if(sum==s){
                ans.push_back(i+1);// 1 base indexing 
                ans.push_back(j+1);
                break;
            }
            j++;
        }
       if(!ans.empty()){
           return ans;
       }
      else{ 
          return {-1} ;
      }
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends