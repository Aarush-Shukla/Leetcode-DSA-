//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
       vector<int> find(int arr[], int n , int x )
    {
        // code here
        int i=0;
        int j=0;
        vector<int> v;
        bool found = false;
        for(int k=0;k<n;k++){
            if(arr[k] == x){
                if(!found){
                    i = k;
                    j = k;
                    found = true;
                }else{
                    j = k;
                }
            }
        }
        
        if(!found){
            v.push_back(-1);
            v.push_back(-1);
        }else{
            v.push_back(i);
            v.push_back(j);
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends